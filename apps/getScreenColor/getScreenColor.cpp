#include <iostream>
#include <string>
#include <windows.h>

// RGB値を格納する構造体
struct RGB {
    int r, g, b;
};

// 指定した座標 (x, y) の色を取得する関数
RGB GetColorAtPosition(int x, int y) {
    RGB color = { -1, -1, -1 }; // 初期値: エラー時の値

    // デスクトップ全体のデバイスコンテキストを取得
    HDC hdc = GetDC(NULL); // NULLで画面全体を取得
    if (!hdc) {
        std::cerr << "Failed to get device context!" << std::endl;
        return color;
    }

    // 指定座標のピクセルの色を取得
    COLORREF pixelColor = GetPixel(hdc, x, y);
    if (pixelColor == CLR_INVALID) { // エラーの場合
        std::cerr << "Failed to get pixel color at (" << x << ", " << y << ")!" << std::endl;
        ReleaseDC(NULL, hdc);
        return color;
    }

    // 赤、緑、青の成分を構造体に格納
    color.r = GetRValue(pixelColor);
    color.g = GetGValue(pixelColor);
    color.b = GetBValue(pixelColor);

    // デバイスコンテキストを解放
    ReleaseDC(NULL, hdc);

    return color;
}

int main(int argc, char *argv[]) {
	if (argc != 3 && argc != 1) {std::cout << "Usage: getScreenColor <X> <Y>";return 0;}
	int x, y;
	if (argc==1) {
		POINT p;
		GetCursorPos(&p);
		x = p.x;
		y = p.y;
	} else {
		x = std::stoi(argv[1]);
		y = std::stoi(argv[2]);
	}
    // 座標の色を取得
    RGB color = GetColorAtPosition(x, y);

    // 結果を表示
    if (color.r != -1 && color.g != -1 && color.b != -1) {
        std::cout << "Color at (" << x << ", " << y << "): "
                  << "R=" << color.r << " G=" << color.g << " B=" << color.b << std::endl;
    } else {
        std::cerr << "Failed to retrieve color!" << std::endl;
    }
}
