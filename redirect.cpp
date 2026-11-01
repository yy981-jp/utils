#include <string>
#include <span>
#include <cstdlib>


int main(int argc, char *argv[]) {
	std::string cmd;
	std::span<char*> input(argv+1 ,argc-1);
	for (const char* i : input) {
		cmd+= std::string(i) + " ";
	}
	std::system(cmd.c_str());
}