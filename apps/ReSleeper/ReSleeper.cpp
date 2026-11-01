#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <windows.h>


bool operation = false;
bool continue_permission = true;
HHOOK keyboardHook;
HHOOK mouseHook;

// キーボードフックのコールバック関数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        // std::cout << "キーが押されました" << std::endl;
		operation = true;
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

// マウスフックのコールバック関数
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        // std::cout << "カーソルが移動しました" << std::endl;
		operation = true;
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

inline void askUserForSleep() {
	if (continue_permission) {
		continue_permission=false;
	} else {
		continue_permission=true;
		return;
	}
	operation = false;
	std::this_thread::sleep_for(std::chrono::minutes(1));
	if (!operation) {
		auto t = std::time(nullptr);
		std::cout << "勝手な起動: " << std::put_time(std::localtime(&t), "%Y/%m/%d_%H:%M:%S") << "\n";
		std::system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
		operation = false;
	} else {
		auto t = std::time(nullptr);
		std::cout << "ユーザーによる起動: " << std::put_time(std::localtime(&t), "%Y/%m/%d_%H:%M:%S") << "\n";
		operation = false;
	}
}

// スリープ解除検知
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_POWERBROADCAST) {
        if (wParam == PBT_APMRESUMEAUTOMATIC || wParam == PBT_APMRESUMESUSPEND) std::thread(askUserForSleep).detach();
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
	// キーボードフックの設定
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    // マウスフックの設定
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);

    // ウィンドウクラスの登録
    const char CLASS_NAME[] = "ReSleeperWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // 隠れたウィンドウの作成
    // HWND hwnd = CreateWindowEx(0, CLASS_NAME, "ReSleeper", 0, 0, 0, 0, 0, nullptr, nullptr, wc.hInstance, nullptr);

    MSG msg;
    // メッセージループ
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // フックを解除
    UnhookWindowsHookEx(keyboardHook);
    UnhookWindowsHookEx(mouseHook);
}