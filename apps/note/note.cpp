#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <QtCore/QString>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSystemTrayIcon>


int main(int argc, char *argv[]) {
	if (!(argc==6 || argc==5)) {
		std::cout << "Usage: <Title> <Message> <MessageIcon(0.NoIcon 1.Information 2.Warning 3.Critical)> <MilliSecondsTimeout> [<IconPath>]\n";
		return 1;
	}
	QApplication app(argc, argv);
	QSystemTrayIcon::MessageIcon mi;
	switch(std::stoi(argv[3])) {
		case 0: mi = QSystemTrayIcon::NoIcon; break;
		case 1: mi = QSystemTrayIcon::Information; break;
		case 2: mi = QSystemTrayIcon::Warning; break;
		case 3: mi = QSystemTrayIcon::Critical; break;
	}
	QSystemTrayIcon trayIcon;
	if (argc==6) trayIcon.setIcon(QIcon(argv[6])); else trayIcon.setIcon(QIcon("C:/Windows/System32/SecurityAndMaintenance.png"));
	trayIcon.show();
	trayIcon.showMessage(QString::fromLocal8Bit(argv[1]), QString::fromLocal8Bit(argv[2]), mi, std::stoi(argv[4]));
	// std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(argv[4])+1000));
}
