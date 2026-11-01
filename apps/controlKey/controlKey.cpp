#include <iostream>
#include <windows.h>
#include <stdexcept>
#include <bitset>
#include <thread>
#include <chrono>
#include <cmath>


std::bitset<6> pressed(0);
short speed = 10;
HHOOK hHook = NULL;
bool isHotKeyPressed = false;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;

        bool shiftPressed = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
        bool altPressed = (GetAsyncKeyState(VK_MENU) & 0x8000) != 0;
        bool ctrlPressed = (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0;
        bool upPressed = (pKeyBoard->vkCode == VK_UP);
        bool rightPressed = (pKeyBoard->vkCode == VK_UP);
        bool downPressed = (pKeyBoard->vkCode == VK_UP);
        bool leftPressed = (pKeyBoard->vkCode == VK_UP);
        bool leftClickPressed = (pKeyBoard->vkCode == VK_OEM_PLUS);
        bool rightClickPressedPressed = (pKeyBoard->vkCode == VK_OEM_1);

        if (shiftPressed && altPressed && ctrlPressed && wParam == WM_KEYDOWN && 
			(upPressed||rightPressed||downPressed||leftPressed||leftClickPressed||rightClickPressedPressed)) {
            if (!isHotKeyPressed) {
                isHotKeyPressed = true;
            }
        } else if (wParam == WM_KEYUP) {
            // std::cout << "Hotkey  Released" << std::endl;
			pressed = 0;
            isHotKeyPressed = false;
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void click(bool type) {
    INPUT inputs[2] = {0};
    inputs[0].type = INPUT_MOUSE;
    inputs[1].type = INPUT_MOUSE;
	if (type) {
		inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	} else {
		inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	}
    SendInput(2, inputs, sizeof(INPUT));
}

int main() {
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
	std::thread([]{
		POINT p;
		while(true) {
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
			if (!pressed.any()) continue;
			
			double dx = 0;
			double dy = 0;

			if (pressed[0]) dy -= speed;
			if (pressed[1]) dx += speed;
			if (pressed[2]) dy += speed;
			if (pressed[3]) dx -= speed;
			if (pressed[4]) click(true);
			if (pressed[5]) click(true);

			if (dx != 0 && dy != 0) {
				dx = dx / std::sqrt(2.0);
				dy = dy / std::sqrt(2.0);
			} else if (dx == 0 && dy == 0) pressed = 0;
			
			GetCursorPos(&p);
			SetCursorPos(p.x+dx, p.y+dy);
		}
	}).detach();
	
	std::thread([]{
		while(true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			/*std::cout << "pressed [0]: " << pressed[0] << "   [1]: " << pressed[1] << "   [2]: " << pressed[2] << "   [3]: " << pressed[3] 
					  << "   [4]: " << pressed[5] << "   [4]: " << pressed[5]  << "\n";*/
		}
	}).detach();
	
	if (!RegisterHotKey(nullptr, 991071, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_UP)) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 991072, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_RIGHT)) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 991073, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_DOWN)) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 991074, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_LEFT)) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 991075, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_OEM_PLUS)) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 991076, MOD_SHIFT|MOD_ALT|MOD_CONTROL, VK_OEM_1)) throw std::runtime_error("HotKey設定失敗");
	
	MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
		if (msg.message == WM_HOTKEY) {
			if (msg.wParam == 991071) pressed.set(0);/* else pressed.reset(0);*/ // 上
			if (msg.wParam == 991072) pressed.set(1);/* else pressed.reset(1);*/ // 右
			if (msg.wParam == 991073) pressed.set(2);/* else pressed.reset(2);*/ // 下
			if (msg.wParam == 991074) pressed.set(3);/* else pressed.reset(3);*/ // 左
			if (msg.wParam == 991075) pressed.set(4);/* else pressed.reset(4);*/ // 左クリック
			if (msg.wParam == 991076) pressed.set(5);/* else pressed.reset(5);*/ // 右クリック
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
    }
}