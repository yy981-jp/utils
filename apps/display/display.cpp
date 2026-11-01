#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>


int main() {
	char i;
	std::cout << "Mode [i:Info, s:set, r:rotate]: ";
	std::cin >> i;
	if (i=='i') {
		
		
		
		std::cout << "現在の画面解像度: " << GetSystemMetrics(SM_CXSCREEN) << "x" << GetSystemMetrics(SM_CYSCREEN) << "\n";
		DEVMODE devMode;
		int modeNum = 0;
		while (EnumDisplaySettings(NULL, modeNum, &devMode)) {
		std::cout << "Mode " << modeNum << ": "
				  << devMode.dmPelsWidth << "x" << devMode.dmPelsHeight << " @ "
				  << devMode.dmBitsPerPel << " bits, "
				  << devMode.dmDisplayFrequency << " Hz" << std::endl;
		modeNum++;
		}
		
		
		
	} else if (i=='s') {
		
		
		
		DEVMODE devMode;
		int width, height;
		std::cout << "新しい幅: ";
		std::cin >> width;
		
		std::cout << "新しい高さ: ";
		std::cin >> height;

		memset(&devMode, 0, sizeof(devMode));
		devMode.dmSize = sizeof(devMode);
		devMode.dmPelsWidth = width;  // 幅
		devMode.dmPelsHeight = height; // 高さ
		devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

		// 解像度を変更
		LONG result = ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
		if (result == DISP_CHANGE_SUCCESSFUL) {
			std::cout << "解像度の変更に成功しました。Ctrl+Cで終了\n";
			std::this_thread::sleep_for(std::chrono::hours(10000));
		} else {
			std::cerr << "解像度の変更に失敗しました。エラーコード: " << result << std::endl;
		}
		
		
		
	} else if (i=='r') {
		
		
		
		int i;
		std::cout << "[0:0°, 1:90°, 2:180°, 3:270°]: ";
		std::cin >> i;
		DWORD orientation;
		switch(i) {
			case 0:
				orientation = DMDO_270;
				break;
				case 1:
				orientation = DMDO_DEFAULT;
				break;
			case 2:
				orientation = DMDO_90;
				break;
			case 3:
				orientation = DMDO_180;
				break;
			default:
				std::cerr << "Invalid orientation value." << std::endl;
				break;
		}
		
		DEVMODE devMode;
		memset(&devMode, 0, sizeof(devMode));
		devMode.dmSize = sizeof(devMode);

		if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
			if (orientation == DMDO_90 || orientation == DMDO_270) {
				if (devMode.dmPelsWidth < devMode.dmPelsHeight) {
					std::swap(devMode.dmPelsWidth, devMode.dmPelsHeight);
				}
			} else {
				if (devMode.dmPelsWidth > devMode.dmPelsHeight) {
					std::swap(devMode.dmPelsWidth, devMode.dmPelsHeight);
				}
			}
			devMode.dmDisplayOrientation = orientation;

			LONG result = ChangeDisplaySettings(&devMode, CDS_UPDATEREGISTRY);
			if (result == DISP_CHANGE_SUCCESSFUL) {
				std::cout << "画面の向きの変更に成功しました。\n";
			} else {
				std::cerr << "Failed to change display orientation. Error code: " << result << "\n";
			}
		} else {
			std::cerr << "Failed to enumerate display settings." << std::endl;
		}
		
		
		
	} else std::cerr << "InputError\n";
}