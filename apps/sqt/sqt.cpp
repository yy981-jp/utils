#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <yy981/vector.h>

namespace fs = std::filesystem;

void multi() {
	std::string input;
	std::vector<std::string> list;
	while (true) {
		std::getline(std::cin, input);
		if (input == "exit") break;
		if (input.starts_with("#include")) list.emplace_back(input.substr(10,input.size()-11));
		else list.emplace_back(input);
	}
	for (const auto x: fs::recursive_directory_iterator("c:/msys64/mingw64/include/qt6")) {
		fs::path f = x.path();
		if (x.is_regular_file() && vct::contains(list,f.filename().string())) {
			std::cout << "#include <" + f.parent_path().stem().string() + "/" + f.filename().string() + ">\n";
			std::erase_if(list,[&f](std::string x) { return x == f.filename().string(); });
			if (list.empty()) return;
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		multi();
		return 0;
	}
	for (const auto x: fs::recursive_directory_iterator("c:/msys64/mingw64/include/qt6")) {
		fs::path f = x.path();
		if (x.is_regular_file() && f.filename().string()==argv[1]) std::cout << f.parent_path().stem().string() + "/" + f.filename().string();
	}
}