#include <iostream>
#include <windows.h>

HWND targetWindow;

void sendKeyInput(WORD key, bool keyUp = false) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    if (keyUp) {
        input.ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(1, &input, sizeof(INPUT));
}

void keyPush() {
	for (char key = 'A'; key <= 'Z'; ++key) {
		if (key!='Q'||key!='X') {
			sendKeyInput(key);
			sendKeyInput(key,true);
		}
	}
    /*sendKeyInput(VK_SHIFT);
	sendKeyInput('1');
	sendKeyInput(VK_OEM_2);
	sendKeyInput(VK_OEM_2,true);
	sendKeyInput(VK_SHIFT,true);*/
	sendKeyInput(VK_OEM_MINUS);
	sendKeyInput(VK_OEM_MINUS,true);
	sendKeyInput(VK_OEM_PERIOD);
	sendKeyInput(VK_OEM_PERIOD,true);
	/*sendKeyInput(VK_OEM_COMMA);
	sendKeyInput(VK_OEM_COMMA,true);*/
}

int main() {
    targetWindow = GetForegroundWindow();

    if (!targetWindow) {std::cerr << "ターゲットウィンドウ取得失敗";return 1;}
	if (!RegisterHotKey(NULL, 298100, MOD_NOREPEAT, VK_F8)) {std::cerr << "グローバルホットキーの登録に失敗しました。" << std::endl;std::cin.get();return 1;}
	std::cout << "F8で最前面のウィンドウに対して実行\n";

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (msg.message == WM_HOTKEY && msg.wParam == 298100) keyPush();
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}