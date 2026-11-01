#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <algorithm>
#include <yy981/sha256.h>
#include <yy981/return.h>

namespace fs = std::filesystem;


bool perfect(true);


int main(int argc, char* argv[]) {
	if (argc != 3) return_u("DC Dir1 Dir2");
	fs::path d1(argv[1]);
	fs::path d2(argv[2]);
	if (!fs::exists(d1)) return_e("D1パスの示す場所が存在しません");
	if (!fs::exists(d2)) return_e("D2パスの示す場所が存在しません");
	
	std::unordered_map<std::string,std::vector<fs::path>> list;
	
	// Dir1
	for (const auto x: fs::recursive_directory_iterator(d1)) {
		list[sha256f(x.path())].emplace_back(fs::relative(x.path(),d1));
	}

	// Dir2
	for (const auto x: fs::recursive_directory_iterator(d2)) {
		std::string hash = sha256f(x.path());
		if (!list.contains(hash)) {
			perfect = false;
			std::cout << "D2にのみ存在するファイル: " << x.path().string() << "\n";
			continue;
		}
		fs::path p = fs::relative(x.path(),d2);
		std::vector<fs::path>& vec = list[hash];
		auto it = std::find(vec.begin(),vec.end(),p);
		if (it == vec.end()) {
			perfect = false;
			std::cout << "D2にのみ存在するファイル: " << x.path().string() /*<< "     同じ内容のファイルが見つかりました\n"*/ << "\n";
			// for (const fs::path& c: vec) std::cout << "\t" << c << "\n";
		} else {
			vec.erase(it);
			// cout=opt "両方に存在"
		}
	}
	
	for (const auto& [hash,vec]: list) {
		for (const fs::path& f: vec) {
			perfect = false;
			std::cout << "D1にのみ存在するファイル: " << (d2/f).string() << "\n";
		}
	}
	
	if (perfect) std::cout << "両ディレクトリ間に相違点は検出されませんでした\n";
}