#include <iostream>
#include <yy981/return.h>


int main(int argc, char *argv[]) {
	if (argc < 4) return_u("運動強度 <年齢> <安静時脈拍数> <運動時脈拍数>");
    int restingHeartRate, exerciseHeartRate, age;
	age = std::stoi(argv[1]);
	restingHeartRate = std::stoi(argv[2]);
	exerciseHeartRate = std::stoi(argv[3]);

    double changeRate = ((exerciseHeartRate - restingHeartRate) * 100.0) / ((220 - age)-restingHeartRate);
    std::cout << "計算結果: " << changeRate << "\n";
}