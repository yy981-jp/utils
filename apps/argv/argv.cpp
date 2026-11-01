#include <iostream>


int main(int argc, char *argv[]) {
	for (int i = 0; i <= argc-1; i++) std::cout << "[" << i << "] " << argv[i] << "\n";
}