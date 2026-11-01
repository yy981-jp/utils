#include <iostream>
#include <string>
#include <filesystem>
#include <yy981/return.h>
namespace fs = std::filesystem;


int main(int argc, char *argv[]) {
	if (argc < 4) return_u("findSpace <対象フォルダ> <拡張子(.無し)> <start> <end>");

	if (!fs::exists(argv[1])) throw std::runtime_error("パスが無効です");
	fs::current_path(argv[1]);
	std::string extension = "." + std::string(argv[2]);
	for (int i = std::atoi(argv[3]); i <= std::atoi(argv[4]); i++) {
		if (!fs::exists(std::to_string(i)+extension)) std::cout << i << "\n";
	}
}