#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <QtCore/QCoreApplication>
#include <QtGui/QClipboard>
#include <QtGui/QImage>
#include <QtCore/QMimeData>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
	
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (!mimeData->hasImage()) {
        std::cerr << "エラー: クリップボードに画像がありません。";
        return 1;
    }

    QImage image = qvariant_cast<QImage>(mimeData->imageData());
    QString tempFilePath = QString::fromStdString(std::string(std::getenv("temp"))) + "\\image_" + QString::fromStdString(boost::uuids::to_string(uuid)) + ".png";

    if (!image.save(tempFilePath)) {
        std::cerr << "エラー: 画像を保存できませんでした。";
        return 2;
    }
    clipboard->setText(tempFilePath);
    return 0;
}
