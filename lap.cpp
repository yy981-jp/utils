#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <yy981/string.h>
#include <yy981/return.h>
#include <yy981/time.h>


int main(int argc, char *argv[]) {
	std::cout << "要素数: " << argc-1 << "\n";
	if (argc < 3) return_u("要素数が足りません\n");
	
	// 入力データ処理
	std::vector<int> times;
	std::span<char*> raw_input(argv+1, argc-1);
	for (const char* c: raw_input) {
		std::vector<int> input;
		for (std::string e : st::split(c,":")) input.emplace_back(std::stoi(e));
		switch(input.size()) {
			case 1:
				times.emplace_back(input[0]);
			break; case 2:
				times.emplace_back(input[0]*60 + input[1]);
			break; case 3:
				times.emplace_back(input[0]*360 + input[1]*60 + input[2]);
			break;
		}
	}
	
	// for (int a : times) std::cout << "DEBUG::: " << a << "\n";

	// データ出力
	for (int i = 1; i <= times.size()-1; i++) {
		std::array<int,3> output = splitTime(times[i] - times[i-1]);
		if (output[0]==0) {
			if (output[1]==0) {
				std::cout << "[" << i << "] " << output[2] << "\n";
			} else std::cout << "[" << i << "] " << output[1] << ":" << output[2] << "\n";
		} else std::cout << "[" << i << "] " << output[0]  << ":" << output[1] << ":" <<  output[2] << "\n";
	}
}