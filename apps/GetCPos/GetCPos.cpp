#include <iostream>
#include <windows.h>


int main() {
	POINT p;
	while(true) {
		std::cin.get();
		GetCursorPos(&p);
		std::cout << "X: " << p.x << " Y: " << p.y;
	}
}