#include <iostream>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QApplication>
#include <chrono>
#include <thread>


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QGraphicsView window;
	
	std::thread([&] {
		while(true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "X: " << window.x() << " Y: " << window.y() << "\n";
		}
	}).detach();
	
	window.show();
	return app.exec();
}