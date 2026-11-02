#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// ICOヘッダー構造体
struct IcoHeader {
    uint16_t reserved;  // 予約領域（常に0）
    uint16_t type;      // ファイルタイプ（1: ICO, 2: CUR）
    uint16_t count;     // 画像エントリの数
};

// ICOエントリ構造体
struct IcoEntry {
    uint8_t width;         // 画像の幅（256は0と記録）
    uint8_t height;        // 画像の高さ（256は0と記録）
    uint8_t colorCount;    // カラーパレットの数（0でOK）
    uint8_t reserved;      // 予約領域（常に0）
    uint16_t planes;       // カラープレーン数（常に1）
    uint16_t bitCount;     // ビット深度（32: RGBA）
    uint32_t sizeInBytes;  // 画像データのバイト数
    uint32_t offset;       // 画像データへのオフセット
};


void pngToIco(const std::string inputPngPath, const std::string outputIcoPath) {
    int width, height, channels;
    uint8_t* pngData = stbi_load(inputPngPath.c_str(), &width, &height, &channels, 4); // RGBAとして読み込む
    if (!pngData) {
        std::cerr << "Failed to load PNG: " << inputPngPath << "\nEnterキーで終了します";
		std::cin.get();
        return;
    }

    if (width != 256 || height != 256) {
        std::cerr << "Only 256x256 PNGs are supported.\nEnterキーで終了します";
		stbi_image_free(pngData);
		std::cin.get();
        return;
    }

    // ICOファイルの作成
    std::ofstream icoFile(outputIcoPath, std::ios::binary);
    if (!icoFile) {
        std::cerr << "Failed to create ICO file: " << outputIcoPath << "\nEnterキーで終了します";
        stbi_image_free(pngData);
		std::cin.get();
        return;
    }

    // ヘッダーの書き込み
    IcoHeader header = {0, 1, 1};
    icoFile.write(reinterpret_cast<const char*>(&header), sizeof(header));

    // エントリの書き込み
    IcoEntry entry = {};
    entry.width = 0;  // 256は0と記録
    entry.height = 0; // 同上
    entry.colorCount = 0;
    entry.reserved = 0;
    entry.planes = 1;
    entry.bitCount = 32;
    entry.sizeInBytes = width * height * 4 + 40; // DIBヘッダー + 画像データ
    entry.offset = sizeof(IcoHeader) + sizeof(IcoEntry); // ヘッダー後の位置

    icoFile.write(reinterpret_cast<const char*>(&entry), sizeof(entry));

    // DIBヘッダーの書き込み
    uint32_t dibHeader[10] = {
        40,             // ヘッダーサイズ
        static_cast<uint32_t>(width),
        static_cast<uint32_t>(height * 2), // 上下反転
        1 | (32 << 16), // プレーン数とビット深度
        0, 0, 0, 0, 0, 0
    };
    icoFile.write(reinterpret_cast<const char*>(dibHeader), sizeof(dibHeader));

    // ピクセルデータの書き込み（上下反転）
    for (int y = height - 1; y >= 0; --y) {
        icoFile.write(reinterpret_cast<const char*>(pngData + y * width * 4), width * 4);
    }

    stbi_image_free(pngData);
    icoFile.close();
}

int main(int argc, char** argv) {
	pngToIco(std::string(argv[1]),std::string(argv[2]));
}