#include <iostream>
#include <string>

#include <windows.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <yy981/return.h>

void copyToClipboard(const std::string& text) {
    if (!OpenClipboard(nullptr)) return;
    EmptyClipboard();

    // ANSI文字列ならCF_TEXT、UTF-8ならCF_UNICODETEXTに変換
    size_t len = text.size() + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    if (!hMem) {
        CloseClipboard();
        return;
    }

    memcpy(GlobalLock(hMem), text.c_str(), len);
    GlobalUnlock(hMem);

    SetClipboardData(CF_TEXT, hMem); // CF_UNICODETEXTならUTF-16に変換する必要あり
    CloseClipboard();
}

std::string OCR(PIX* image) {
	tesseract::TessBaseAPI api;

	// 初期化 (データパスorNULL,言語)
	if (api.Init(NULL, "eng")) return_e("Tesseractの初期化に失敗しました");
	api.SetVariable("tessedit_char_whitelist", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.-, ");

	// Leptonica
	if (!image) return_e("画像の読み込みに失敗しました");

	// OCR (UTF-8)
	api.SetImage(image);
	char *outText = api.GetUTF8Text();
	std::string result(outText);

	// 後処理
	delete[] outText;
	pixDestroy(&image);
	api.End();

	return result;
}

int main(int argc, char* argv[]) {
	if (argc != 2) return_e("argc!=2");
	copyToClipboard(OCR(pixRead(argv[1])));
}