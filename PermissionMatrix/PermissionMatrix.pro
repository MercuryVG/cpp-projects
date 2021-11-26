QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deletefilewindow.cpp \
    deleteuserwindow.cpp \
    file.cpp \
    filewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    permissions.cpp \
    userwindow.cpp \
    User.cpp

HEADERS += \
    deletefilewindow.h \
    deleteuserwindow.h \
    file.h \
    filewindow.h \
    mainwindow.h \
    permissions.h \
    permissions_list.h \
    roles_list.h \
    userwindow.h \
    User.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Files.txt \
    Users.txt
