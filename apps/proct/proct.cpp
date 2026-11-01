#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <yy981/def.h>
#include <yy981/string.h>
#include <yy981/return.h>
#include <yy981/time.h>

void wait(int hou, int min, int sec) {
	// 現在時刻取得
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::tm* timeInfo = std::localtime(&currentTime);

	// ターゲット時間設定
	timeInfo->tm_hour = hou;
	timeInfo->tm_min = min;
	timeInfo->tm_sec = sec;

	// ターゲット時間をchronoで扱える型へ変換
	auto targetTime = std::chrono::system_clock::from_time_t(std::mktime(timeInfo));

	// もし設定時間が過去なら翌日に設定
	if (targetTime < now) {
		targetTime += std::chrono::hours(24);
	}

	// 待機時間計算
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(targetTime - now);

	std::cout << "実行予定時刻: " << std::put_time(timeInfo, "%H:%M:%S") << std::endl;
	std::this_thread::sleep_for(duration); // 待機
}

int main(ARGC) {
	if (argc < 3) return_u("proct <日時> <プログラムのパス>...\n時刻は次のように表記してください: **h**m**s");
	std::vector<std::string> input = st::charV(argc,argv);
	st::splitsi time = st::splitiFromList(input[1],{"h","m","s"});
	input.erase(input.begin(),input.begin()+2);
	int hour, minute, second;
	if (time["h"].empty()) hour = getCTime(tu::h); else hour = time["h"][0];
	if (time["m"].empty()) {
		if (time["s"].empty()) minute = 0; else minute = getCTime(tu::m);
	} else minute = time["m"][0];
	if (time["s"].empty()) second = 0; else {
		second = time["s"][0];
		if (second <= getCTime(tu::s)) ++minute;
		if (minute < getCTime(tu::m)) ++minute;
	}
	if (time["m"].empty() || time["s"].empty())

	wait(hour, minute, second);
	
	for (std::string e: input) {
		std::system(("start "+e).c_str());
	}
}
