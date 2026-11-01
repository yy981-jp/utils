#include <iostream>
#include <windows.h>
#include <yy981/string.h>


int main() {
	while (true) {
		std::string input;
		std::cin >> input;
		std::vector<int> o = st::spliti(input,",");
		if (o.size() != 2) continue;
		SetCursorPos(o[0],o[1]);
	}
}