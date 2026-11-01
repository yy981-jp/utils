#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>


int getMemoryUsage() {
    // メモリ情報を格納する構造体
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    // メモリ情報を取得
    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
        // DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
        double memoryUsagePercentage = (double)memInfo.ullAvailPhys / (double)totalPhysMem * 100.0;  // 100-使用率
		return static_cast<int>(memoryUsagePercentage);
    } else {
		return -1;
    }
}

int main() {
	bool running = true;
	std::thread([&running]{
		while(true) {
			new long double;
			if (!running) std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}).detach();
	std::thread([]{
		std::cin.get();
		exit(0);
	}).detach();
	while(true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (getMemoryUsage()<=1) running = false; else running = true;
	}
}