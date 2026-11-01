#include <iostream>
#include <string>
#include <windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <ctime>
#include <sstream>
#include <thread>


cv::VideoCapture cap0, cap1;
cv::Size cap0Size;
bool stopRecording = false;

std::string getCurrentDateTime() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d.%H%M-%S");
    return oss.str();
}

void print0() {
	if (cap0.isOpened()) cap0.open(0);
	std::string path = "c:/cap/" + getCurrentDateTime() + ".jpg";
	cv::Mat img, imgR;
	cap0.read(img);
	cv::resize(img,imgR,cap0Size);
	cv::imwrite(path, imgR);
}

void print1() {
	std::string path = "c:/cap/" + getCurrentDateTime() + ".jpg";
	cv::Mat img, imgR;
	cap1.open(1);
	cap1.read(img);
	cv::resize(img,imgR,cv::Size(static_cast<int>(cap1.get(cv::CAP_PROP_FRAME_WIDTH))*2,static_cast<int>(cap1.get(cv::CAP_PROP_FRAME_HEIGHT))*2));
	cap1.release();
	cv::imwrite(path, imgR);
}


/*void recordVideo(int capN) {
    std::string path = "c:/cap/" + getCurrentDateTime() + ".mp4";
    cap.open(capN);
	
    writer.open(path, cv::VideoWriter::fourcc('M', 'P', '4', 'V'), 30, 
	cv::Size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)), static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT))));

    cv::Mat frame;
    isRecording = true;
    while (!stopRecording) {
        cap.read(frame);
        if (frame.empty()) break;
        writer.write(frame);
    }

    cap.release();
    writer.release();
    std::cout << "Video saved to " << path << std::endl;
    isRecording = false;
}*/



int main() {
	// 0:i 1:o
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_FATAL);
	if (!RegisterHotKey(nullptr, 190003001, MOD_SHIFT|MOD_ALT, '0')) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 190003002, MOD_SHIFT|MOD_ALT, '1')) throw std::runtime_error("HotKey設定失敗");
	if (!RegisterHotKey(nullptr, 190003003, MOD_SHIFT|MOD_ALT, '3')) throw std::runtime_error("HotKey設定失敗");
	cap0.open(0);
	cap0Size = cv::Size(static_cast<int>(cap0.get(cv::CAP_PROP_FRAME_WIDTH))*2,static_cast<int>(cap0.get(cv::CAP_PROP_FRAME_HEIGHT))*2);
	cap0.release();
	std::cout << "Program.Started\n";

	MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (msg.message == WM_HOTKEY && msg.wParam == 190003001) print0();
        if (msg.message == WM_HOTKEY && msg.wParam == 190003002) print1();
        if (msg.message == WM_HOTKEY && msg.wParam == 190003003) []{if (cap0.isOpened()) cap0.release(); else cap0.open(0);};
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}