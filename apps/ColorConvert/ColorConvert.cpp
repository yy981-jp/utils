#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <yy981/colorConverter.h>
#include <yy981/andor.h>


inline void usage() {
	std::cout << "Usage: ColorConverter <変換元規格> <変換先規格> {入力要素}\n以下{入力要素}にあたる部分\n"
			  << "[RGB]:   <赤(0~255)> <緑(0~255)> <青(0~255)>\n"
			  << "[CMYK]:  <シアン(0~100%)> <マゼンタ(0~100%)> <イエロー(0~100%)> <キー(ブラック)(0~100%)>\n"
			  << "[HSL]:   <色相(0~360)> <彩度(0~100%)> <輝度(0~100%)>\n"
			  << "[HSB]:   <色相(0~360)> <彩度(0~100%)> <明度(0~100%)>\n"
			  << "[LAB]:   <明度(0~100)> <a軸(-128~127)> <b軸(-128~127)>\n";
}

int toID(char* argv[], int input) {
	std::string inputString = std::string(argv[input]);
	int id;
	if (is_or(inputString, "RGB", "rgb", "Rgb")) id = 1;
	else if (is_or(inputString, "HEX", "hex", "Hex")) id = 2;
	else if (is_or(inputString, "CMYK", "cmyk", "Cmyk")) id = 3;
	else if (is_or(inputString, "HSL", "hsl", "Hsl")) id = 4;
	else if (is_or(inputString, "HSB", "hsb", "Hsb")) id = 5;
	else if (is_or(inputString, "LAB", "lab", "Lab")) id = 6;
	else {
		if (input==1) {std::cerr << "変換元規格(第一引数)が間違っています\n";usage();}
		else if (input==2) {std::cerr << "変換先規格(第二引数)が間違っています\n";usage();}
	}
	return id;
}


int main(int argc, char *argv[]) {
	if (argc<=1 || std::string(argv[1])=="help") {usage();return 0;}
	int id1 = toID(argv,1);
	int id2 = toID(argv,2);
	float argvInt[4];
	if (argc==4) {
		if (std::string(argv[3]).substr(0,1) == "#") argvInt[0] = std::stoi(std::string(argv[3]).substr(1), nullptr, 16);
		else argvInt[0] = std::stoi(argv[3], nullptr, 16);
	}
	else if (argc==6) {
		std::string argvString[3];
		argvString[0] = std::string(argv[3]);
		argvString[1] = std::string(argv[4]);
		argvString[2] = std::string(argv[5]);
		if (argvString[0].back() == '%') argvInt[0] = std::stof(argvString[0].substr(0, argvString[0].size()-1)); else argvInt[0] = std::stof(argvString[0]);
		if (argvString[0].back() == '%') argvInt[1] = std::stof(argvString[1].substr(0, argvString[1].size()-1)); else argvInt[1] = std::stof(argvString[1]);
		if (argvString[0].back() == '%') argvInt[2] = std::stof(argvString[2].substr(0, argvString[2].size()-1)); else argvInt[2] = std::stof(argvString[2]);
	}
	else if (argc==7) {
		argvInt[0] = std::stof(argv[3]);
		argvInt[1] = std::stof(argv[4]);
		argvInt[2] = std::stof(argv[5]);
		argvInt[3] = std::stof(argv[6]);
	}
	
	switch(id2) {
		// toRGB
		case 1: {
			ccv::RGB output;
			switch(id1) {
				case 1: {
					output = ccv::RGB(argvInt[0],argvInt[1],argvInt[2]);
				} break;
				case 2: {
					output = ccv::hexToRgb(argvInt[0]);
				} break;
				case 3: {
					output = ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3]));
				} break;
				case 4: {
					output = ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100));
				} break;
				case 5: {
					output = ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100));
				} break;
				case 6: {
					output = ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2]));
				} break;
			}
			std::cout << "RGB(" << output.r << "," << output.g << "," << output.b << ")\n";
		} break;
		
		// toHEX
		case 2: {
			int output;
			switch(id1) {
				case 1: {
					output = ccv::rgbToHex(ccv::RGB(argvInt[0],argvInt[1],argvInt[2]));
				} break;
				case 2: {
					output = argvInt[0];
				} break;
				case 3: {
					output = ccv::rgbToHex(ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3])));
				} break;
				case 4: {
					output = ccv::rgbToHex(ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 5: {
					output = ccv::rgbToHex(ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 6: {
					output = ccv::rgbToHex(ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2])));
				} break;
			}
			std::cout << "HEX: #" << std::hex << output << "\n";
		} break;
		
		// toCMYK
		case 3: {
			ccv::CMYK output;
			switch(id1) {
				case 1: {
					output = ccv::rgbToCmyk(ccv::RGB(argvInt[0],argvInt[1],argvInt[2]));
				} break;
				case 2: {
					output = ccv::rgbToCmyk(ccv::hexToRgb(argvInt[0]));
				} break;
				case 3: {
					output = ccv::rgbToCmyk(ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3])));
				} break;
				case 4: {
					output = ccv::rgbToCmyk(ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 5: {
					output = ccv::rgbToCmyk(ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 6: {
					output = ccv::rgbToCmyk(ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2])));
				} break;
			}
			std::cout << "CMYK(" << output.c << ", " << output.m << ", " << output.y << ", " << output.k << ")\n";
		} break;
		
		// toHSL
		case 4: {
			ccv::HSL output;
			switch(id1) {
				case 1: {
					output = ccv::rgbToHsl(ccv::RGB(argvInt[0],argvInt[1],argvInt[2]));
				} break;
				case 2: {
					output = ccv::rgbToHsl(ccv::hexToRgb(argvInt[0]));
				} break;
				case 3: {
					output = ccv::rgbToHsl(ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3])));
				} break;
				case 4: {
					output = ccv::rgbToHsl(ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 5: {
					output = ccv::rgbToHsl(ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 6: {
					output = ccv::rgbToHsl(ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2])));
				} break;
			}
			std::cout << "HSL(" << output.h*1000 << "%," << output.s*100 << "%," << output.l << ")\n";
		} break;
		
		// toHSB
		case 5: {
			ccv::HSB output;
			switch(id1) {
				case 1: {
					output = ccv::rgbToHsb(ccv::RGB(argvInt[0],argvInt[1],argvInt[2]));
				} break;
				case 2: {
					output = ccv::rgbToHsb(ccv::hexToRgb(argvInt[0]));
				} break;
				case 3: {
					output = ccv::rgbToHsb(ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3])));
				} break;
				case 4: {
					output = ccv::rgbToHsb(ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 5: {
					output = ccv::rgbToHsb(ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 6: {
					output = ccv::rgbToHsb(ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2])));
				} break;
			}
			std::cout << "HSB(" << output.h*100 << "%," << output.s*100 << "%," << output.b << ")\n";
		} break;
		
		// toLab
		case 6: {
			ccv::Lab output;
			switch(id1) {
				case 1: {
					output = ccv::rgbToLab(ccv::RGB(argvInt[0],argvInt[1],argvInt[2]));
				} break;
				case 2: {
					output = ccv::rgbToLab(ccv::hexToRgb(argvInt[0]));
				} break;
				case 3: {
					output = ccv::rgbToLab(ccv::cmykToRgb(ccv::CMYK(argvInt[0],argvInt[1],argvInt[2],argvInt[3])));
				} break;
				case 4: {
					output = ccv::rgbToLab(ccv::hslToRgb(ccv::HSL(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 5: {
					output = ccv::rgbToLab(ccv::hsbToRgb(ccv::HSB(argvInt[0],argvInt[1]/100,argvInt[2]/100)));
				} break;
				case 6: {
					output = ccv::rgbToLab(ccv::labToRgb(ccv::Lab(argvInt[0],argvInt[1],argvInt[2])));
				} break;
			}
			std::cout << "Lab(" << output.l << "," << output.a << "," << output.b << ")\n";
		} break;
	}
}
