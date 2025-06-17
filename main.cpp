#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include "GUI/Source/mainwindow.h"
#include "DataBase/DataBaseManager.h"
#include <QDir>

int main(int argc, char *argv[]) {
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(
        Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor
        );

    QApplication app(argc, argv);
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());
    app.setWindowIcon(QIcon(":/img/GUI/Resources/img/hangman_icon_256.png"));

    QString exeDir = QCoreApplication::applicationDirPath();
    QString dbPath  = QDir(exeDir).absoluteFilePath("hangman.db");

    if (!DataBaseManager::instance().openDatabase(dbPath)) {
        QMessageBox msg;
        msg.setWindowTitle("Error");
        msg.setText("Cannot open database at " + dbPath);
        msg.exec();
        return 1;
    }

    MainWindow w;
    w.setWindowTitle("HangMan");
    w.show();
    return app.exec();
}
