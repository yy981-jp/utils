#include <iostream>
#include <opencv2/opencv.hpp>
#include <map>
#include <iomanip> // 16進数出力のために追加

// 比較関数の定義
struct Vec3bComparator {
    bool operator()(const cv::Vec3b& a, const cv::Vec3b& b) const {
        for (int i = 0; i < 3; ++i) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return false;
    }
};

// 色を一意の番号にマッピングする関数
int getColorIndex(const cv::Vec3b& color, std::map<cv::Vec3b, int, Vec3bComparator>& colorMap, int& currentIndex) {
    auto it = colorMap.find(color);
    if (it != colorMap.end()) {
        return it->second;
    } else {
        colorMap[color] = currentIndex;
        return currentIndex++;
    }
}

int main() {
    // 画像を読み込む
    cv::Mat image = cv::imread("C:\cpp\HTML\_.png");

    if (image.empty()) {
        std::cerr << "画像の読み込みに失敗しました" << std::endl;
        return -1;
    }

    std::map<cv::Vec3b, int, Vec3bComparator> colorMap;
    int currentIndex = 0;

    // 画像のピクセルごとに色を番号に変換
    cv::Mat indexedImage(image.rows, image.cols, CV_32S);
    for (int row = 0; row < image.rows; ++row) {
        for (int col = 0; col < image.cols; ++col) {
            cv::Vec3b color = image.at<cv::Vec3b>(row, col);
            int colorIndex = getColorIndex(color, colorMap, currentIndex);
            indexedImage.at<int>(row, col) = colorIndex;
        }
    }

    // 変換結果を表示
    for (int row = 0; row < indexedImage.rows; ++row) {
        for (int col = 0; col < indexedImage.cols; ++col) {
            // 16進数で表示
            std::cout << std::hex << indexedImage.at<int>(row, col) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
