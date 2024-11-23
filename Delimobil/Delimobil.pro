#-------------------------------------------------
#
# Project created by QtCreator 2024-11-05T14:48:56
#
#-------------------------------------------------

QT       += \
         core gui \
         sql \
         location \
         positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Delimobil
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        API/mapwindow.cpp \
        UI/basewidget.cpp \
        UI/calendardialog.cpp \
        UI/careditordialog.cpp \
        UI/carlistwidget.cpp \
        UI/filterdialog.cpp \
        UI/loginwidget.cpp \
        UI/managecarswidget.cpp \
        UI/profilewidget.cpp \
        UI/registrationwidget.cpp \
        UI/rentdialog.cpp \
        database/databasemanager.cpp \
        main.cpp \
        mainwindow.cpp \
        models/authorizeduser.cpp \
        models/car.cpp \
        models/user.cpp \
        repositories/carrepository.cpp \
        repositories/userrepository.cpp \
        services/carservice.cpp \
        services/userservice.cpp

HEADERS += \
        API/mapwindow.h \
        UI/basewidget.h \
        UI/calendardialog.h \
        UI/careditordialog.h \
        UI/carlistwidget.h \
        UI/filterdialog.h \
        UI/loginwidget.h \
        UI/managecarswidget.h \
        UI/profilewidget.h \
        UI/registrationwidget.h \
        UI/rentdialog.h \
        database/databasemanager.h \
        mainwindow.h \
        models/authorizeduser.h \
        models/car.h \
        models/user.h \
        repositories/carrepository.h \
        repositories/userrepository.h \
        services/carservice.h \
        services/userservice.h

FORMS += \
    API/mapwindow.ui \
    UI/basewidget.ui \
    UI/calendardialog.ui \
    UI/careditordialog.ui \
    UI/carlistwidget.ui \
    UI/filterdialog.ui \
        UI/loginwidget.ui \
    UI/managecarswidget.ui \
    UI/profilewidget.ui \
    UI/registrationwidget.ui \
    UI/rentdialog.ui \
        mainwindow.ui \

RESOURCES += resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
