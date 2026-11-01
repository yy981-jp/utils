#include <iostream>
#include <yy981/connect.h>
#include <yy981/return.h>
#include <yy981/sleep.h>


int main(int argc, char *argv[]) {
	if (argc != 3) return_u("tc <mode{s,r}> <name>");
	if (!strcmp(argv[1],"s")) {
		PConnect<int> obj(argv[2],0);
		int input;
		while (true) {
			std::cin >> input;
			obj.write(input);
		}
	} else if (!strcmp(argv[1],"r")) {
		PConnect<int> obj(argv[2]);
		while (true) {
			sleepc(time_s::s,1);
			std::cout << obj.read() << "\n";
		}
	} else return_e("入力エラー");
}