#include <iostream>
#include <string>
#include <windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <ctime>
#include <sstream>
#include <thread>


cv::VideoCapture cap;
bool stopRecording = false;
bool isRecording = false;

std::string getCurrentDateTime() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d.%H%M-%S");
    return oss.str();
}

void print(int capN) {
	std::string path = "c:/cap/" + getCurrentDateTime() + ".jpg";
	cv::Mat img, imgR;
	cap.open(capN);
	cap.read(img);
	std::cout << "\n";
	cv::resize(img,imgR,cv::Size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH))*2,static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT))*2));
	cap.release();
	cv::imwrite(path, imgR);
}

void recordVideo(int capN) {
    std::string path = "c:/cap/" + getCurrentDateTime() + ".mp4";
    cv::VideoWriter writer;

    // カメラをオープン
    cap.open(capN);
    if (!cap.isOpened()) {
        std::cerr << "カメラを開くことができませんでした。" << std::endl;
        return;
    }

    // VideoWriterの設定
    writer.open(path, cv::VideoWriter::fourcc('H', '2', '6', '4'), 30,
                cv::Size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)),
                         static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT))));

    if (!writer.isOpened()) {
        std::cerr << "ビデオファイルを開くことができませんでした。" << std::endl;
        cap.release();
        return;
    }

    // std::cout << "Recording started..." << std::endl;
    cv::Mat frame;
    stopRecording = false;  // 録画停止フラグを初期化

    // 録画ループ
    while (!stopRecording) {
        cap.read(frame);
        if (frame.empty()) break;  // フレーム取得が失敗したら終了
        writer.write(frame);       // フレームをビデオファイルに書き込む
    }

    // リソース解放
    cap.release();
    writer.release();
    // std::cout << "Video saved to " << path << std::endl;
}

void toggleRecording(int capN) {
    if (isRecording) {
        stopRecording = true;  // 録画を停止する
        isRecording = false;
        // std::cout << "Recording stopped.\n";
    } else {
        isRecording = true;
        std::thread(recordVideo, capN).detach();  // 録画を開始する
    }
}



int main() {
	// 0:i 1:o
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
	cap = cv::VideoCapture(0);
	cap.release();
	if (!RegisterHotKey(nullptr, 190003001, MOD_SHIFT|MOD_ALT, '0')) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 190003002, MOD_SHIFT|MOD_ALT, '1')) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 190003003, MOD_SHIFT|MOD_ALT, '3')) throw std::runtime_error("HotKey設定失敗");
	std::cout << "Program.Started\n";

	MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (msg.message == WM_HOTKEY && msg.wParam == 190003001) print(0);
        if (msg.message == WM_HOTKEY && msg.wParam == 190003002) print(1);
        if (msg.message == WM_HOTKEY && msg.wParam == 190003003) toggleRecording(1);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}