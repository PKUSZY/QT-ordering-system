QT       += core gui
QT       +=  sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose2mainwindow.cpp \
    choosepaymainwindow.cpp \
    creatusermainwindow.cpp \
    gukemainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    paymainwindow.cpp \
    shangjiamainwindow.cpp \
    shoppingmainwindow.cpp \
    user.cpp

HEADERS += \
    choose2mainwindow.h \
    choosepaymainwindow.h \
    creatusermainwindow.h \
    gukemainwindow.h \
    mainwindow.h \
    paymainwindow.h \
    shangjiamainwindow.h \
    shoppingmainwindow.h \
    user.h

FORMS += \
    choose2mainwindow.ui \
    choosepaymainwindow.ui \
    creatusermainwindow.ui \
    gukemainwindow.ui \
    mainwindow.ui \
    paymainwindow.ui \
    shangjiamainwindow.ui \
    shoppingmainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Pictures/Screenshots/屏幕截图 2023-12-28 223657.png

RESOURCES += \
    shangjia1.qrc
