#include <QApplication>
#include <database/databasemanager.h>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    DatabaseManager::instance().openConnection();

    auto appResult = app.exec();

    DatabaseManager::instance().closeConnection();

    return appResult;
}
