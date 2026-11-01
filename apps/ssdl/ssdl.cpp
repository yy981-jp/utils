#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <yy981/winMacro.h>
#include <yy981/return.h>


int l = 0;

inline void sendWinPrintScreen() {
    INPUT inputs[4] = {};

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_SNAPSHOT;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_SNAPSHOT;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(4, inputs, sizeof(INPUT));
}

void click(int x, int y) {
	SetCursorPos(x,y);
    INPUT inputs[2] = {0};
    inputs[0].type = INPUT_MOUSE;
	inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    inputs[1].type = INPUT_MOUSE;
	inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(2, inputs, sizeof(INPUT));
}

int main() {
	std::cout << "Program.Start\n";
	std::this_thread::sleep_for(std::chrono::seconds(10));
	click(156,457); // 表示 起動
	std::this_thread::sleep_for(std::chrono::seconds(10));
	while(true) { //ページ内ループ
		l++;
		if (wmc::getColor(450,445)==wmc::clRGB(255,91,26) && wmc::getColor(800,450)==wmc::clRGB(255,91,26)) return_e("L画面");
		click(879,588); // 拡大表示 起動
		std::this_thread::sleep_for(std::chrono::seconds(10));
		sendWinPrintScreen();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		click(1255,26); // 拡大表示 終了
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		click(814,760); // 表示 次
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		if (l==30) {
			click(1047,758); // 表示✖
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (int i = 1; i <= 5; i++) {
				INPUT input = {0};
				input.type = INPUT_KEYBOARD;
				input.ki.wVk = VK_PRIOR;
				input.ki.dwFlags = 0;
				SendInput(1, &input, sizeof(INPUT));
				input.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &input, sizeof(INPUT));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			click(721,234); // ページ 次
			std::this_thread::sleep_for(std::chrono::seconds(10));
			click(156,457); // 表示 起動
			std::this_thread::sleep_for(std::chrono::seconds(10));
			l = 0;
		}
	}
}