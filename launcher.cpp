#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <yy981/qt/shootingLauncher.h>


Ui::SL ui;

int main(int argc, char *argv[]) {
	if (argc==1) {std::cout << "Usage: Launcher <Path> (<f: FullScreen>)\n";return 0;}
    QApplication app(argc, argv);
    QWidget* window = new QWidget;
	ui.setupUi(window);
	QObject::connect(ui.button, &QPushButton::clicked, [&argv]{
		auto t = std::time(nullptr);
		std::cout << std::put_time(std::localtime(&t), "%Y/%m/%d_%H:%M:%S") << "\n";
		std::system(std::string("start " + std::string(argv[1])).c_str());
	});
	if (argc==3 && std::string(argv[2])=="f") window->showFullScreen(); else window->show();
    return app.exec();
}