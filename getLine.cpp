#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

#include <yy981/string.h>
#include <yy981/env.h>

namespace rj = rapidjson;
namespace fs = std::filesystem;


rj::Document readJson(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) throw std::runtime_error("readJson(): ifs");
    rj::IStreamWrapper isw(ifs);
    rj::Document doc;
    doc.ParseStream(isw);
    return doc;
}


size_t count_lines_in_file(const fs::path& path) {
	std::ifstream file(path, std::ios::binary);
	if (!file) return 0;

	std::size_t lines = 0;
	char buffer[1 << 15]; // 32KBバッファ
	while (file.read(buffer, sizeof(buffer)) || file.gcount()) {
		lines += std::count(buffer, buffer + file.gcount(), '\n');
	}
	return lines;
}

void parseCArg(const std::vector<std::string>& carg,
  std::vector<std::string>& ignore, std::vector<std::string>& ext) {
	// set path
	std::string jFilePath;
	switch (carg.size()) {
		case 1: jFilePath = getEnv("localappdata") + "/yy981/getLine.json"; break;
		case 2: jFilePath = carg[1]; break;
		default: {
			std::cout << "Usage: getLine <settingJsonPath>";
			exit(1);
		}
	}

	// load json
	rj::Document j = readJson(jFilePath);
	for (const auto& e: j["ext"].GetArray()) 
		ext.push_back(e.GetString());
	for (const auto& e: j["ignore"].GetArray()) 
		ignore.push_back(e.GetString());
}

int main(int argc, char* argv[]) {
	const auto&& carg = st::charV(argc,argv);
	std::vector<std::string> ext, ignore;
	parseCArg(carg,ignore,ext);

	// show info
	std::cout << "GetLine v1.3 (c) yy981\nTargetExt: ";
	for (const auto& e: ext) std::cout << e << " ";
	std::cout << "\nIgnore: ";
	for (const auto& e: ignore) std::cout << "[" << e << "] ";
	std::cout << "\n\n";

	// init value
	size_t total_lines = 0;
	size_t fileNumber = 0;
	fs::path cd = fs::current_path();
	for (auto it = fs::recursive_directory_iterator(cd); it != fs::end(it); ++it) {
		// check ignore
		std::string&& ps = it->path().string();
		bool ignored = false;
		for (const auto& e : ignore) {
			if (ps.find(e) != std::string::npos) {
				ignored = true;
				break;
			}
		}
		if (ignored) {
			it.disable_recursion_pending();
			continue;
		}
	
		// check ext
		if (it->is_regular_file()) {
			auto p_ext = it->path().extension().string();
			if (is_or(p_ext,ext)) {
				std::size_t lines = count_lines_in_file(it->path());
				std::cout << lines << "\t" << fs::relative(it->path(),cd).string() << "\n";
				total_lines += lines;
				++fileNumber;
			}
		}
	}

	std::cout << "\n合計(" << fileNumber << "ファイル): " << total_lines << "行\n";
}
