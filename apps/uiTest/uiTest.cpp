#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtUiTools/QUiLoader>
#include <QtCore/QFile>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // コマンドライン引数のチェック
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_ui_file>" << std::endl;
        return -1;
    }

    // QUiLoaderを使って.uiファイルを読み込む
    QUiLoader loader;
    QFile file(argv[1]);  // コマンドライン引数で渡された.uiファイルのパスを指定
    if (!file.open(QFile::ReadOnly)) {
        std::cerr << "Cannot open .ui file: " << argv[1] << std::endl;
        return -1;
    }

    QWidget *widget = loader.load(&file);  // ウィジェットとして.uiをロード
    file.close();

    if (!widget) {
        std::cerr << "Failed to load .ui file: " << argv[1] << std::endl;
        return -1;
    }

    widget->show();  // ウィジェットを表示

    return app.exec();
}
