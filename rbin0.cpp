#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "使い方: " << argv[0] << " <ファイル名>" << endl;
		return 1;
	}

	ifstream file(argv[1], ios::binary);
	if (!file) {
		cout << "ファイルを開けない" << endl;
		return 1;
	}

	string binaryStr;
	char byte;
	while (file.get(byte)) {
		binaryStr += bitset<8>(static_cast<unsigned char>(byte)).to_string();
	}

	cout << binaryStr << endl;
}
