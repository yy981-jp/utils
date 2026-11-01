#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: transparency <Path> <R,G,B>\n";
        return 0;
    }

    // 画像を読み込む
    cv::Mat img = cv::imread(std::string(argv[1]));

    if (img.empty()) {
        std::cerr << "画像の読み込みに失敗しました" << std::endl;
        return -1;
    }

    // RGB値をパース
    int r, g, b;
    char delim;
    std::stringstream ss(argv[2]);
    ss >> r >> delim >> g >> delim >> b;

    if (ss.fail() || r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        std::cerr << "RGB値の形式が不正です。0-255の範囲でR,G,Bを指定してください。" << std::endl;
        return -1;
    }

    // 画像をBGRAに変換（アルファチャンネル追加）
    cv::Mat imgWithAlpha;
    cv::cvtColor(img, imgWithAlpha, cv::COLOR_BGR2BGRA);

    // 透過処理
    for (int y = 0; y < imgWithAlpha.rows; y++) {
        for (int x = 0; x < imgWithAlpha.cols; x++) {
            cv::Vec4b &pixel = imgWithAlpha.at<cv::Vec4b>(y, x);
            if (pixel[0] == b && pixel[1] == g && pixel[2] == r) { // 指定されたRGB値の部分
                pixel[3] = 0; // アルファ値を0にする
            }
        }
    }

    // 結果の画像を保存
    cv::imwrite(std::string(argv[1]), imgWithAlpha);

    return 0;
}
