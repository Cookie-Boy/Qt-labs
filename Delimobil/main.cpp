#include <QApplication>
#include "UI/loginwidget.h"
#include <database/databasemanager.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginWidget loginWidget;
    loginWidget.show();

    DatabaseManager::instance().openConnection();

    auto appResult = app.exec();

    DatabaseManager::instance().closeConnection();

    return appResult;
}
