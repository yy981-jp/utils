#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "binaryConvertDB.h"


int main(int argc, char *argv[]) {
	const std::string filename = argv[1];

	// ファイルストリームを開く
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (!file) {
		std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
		return 1;
	}

	// ファイル内容を読み取る
	file.seekg(0, std::ios::end);
	std::streamsize fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<unsigned char> buffer(fileSize);
	file.read(reinterpret_cast<char*>(buffer.data()), fileSize);
	file.close();

	if (buffer.empty()) {
		std::cerr << "ファイルが空です。" << std::endl;
		return 1;
	}

	// ビットを処理するための変数
	unsigned int bitBuffer = 0;
	int bitBufferSize = 0;

	// 11ビットごとのデータを格納するベクター
	std::vector<short> values;

	// バッファからビットを読み取る
	for (unsigned char byte : buffer) {
		bitBuffer = (bitBuffer << 8) | byte; // ビットバッファにバイトを追加
		bitBufferSize += 8;                 // ビットバッファのビット数を更新

		// 11ビットずつ取り出す
		while (bitBufferSize >= 11) {
			short value = (bitBuffer >> (bitBufferSize - 11)) & 0x7FF; // 11ビットを抽出
			values.push_back(value);                                   // 値を保存
			bitBufferSize -= 11;                                       // ビット数を減らす
		}
	}

	// 残ったビットがある場合は無視する（必要ならここで処理）

	// 結果を表示
	std::cout << "11ビットずつの値:" << std::endl;
	for (size_t i = 0; i < values.size(); ++i) {
		std::cout << "Value " << i + 1 << ": " << values[i] << std::endl;
	}

	return 0;
}
