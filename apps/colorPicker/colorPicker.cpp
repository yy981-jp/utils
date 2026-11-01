#include <QtWidgets/QApplication>
#include <QtWidgets/QColorDialog>


int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
	QColorDialog::getColor(Qt::white, nullptr, "ColorPicker");
}