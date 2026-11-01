#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtGui/QPalette>

class BlackWindow : public QMainWindow {
public:
    BlackWindow() {
        // ウィンドウの背景色を設定
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::black);
        this->setPalette(palette);

        // ウィンドウを全画面に設定
        this->setWindowState(Qt::WindowFullScreen);
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // デフォルトディスプレイのサイズを取得
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // 全画面ウィンドウを作成
    BlackWindow blackWindow;
    blackWindow.setGeometry(screenGeometry);
    blackWindow.show();

    return a.exec();
}