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
		// 1バイト（8ビット）を2進数に変換して文字列に追加
		binaryStr += bitset<8>(static_cast<unsigned char>(byte)).to_string();
	}

	// 11ビットずつ区切って表示
	for (size_t i = 0; i < binaryStr.size(); i += 11) {
		cout << binaryStr.substr(i, 11) << endl;
	}

	return 0;
}
