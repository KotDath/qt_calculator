QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttons/binaryoperationbutton.cpp \
    buttons/clearbutton.cpp \
    buttons/dotbutton.cpp \
    buttons/equalbutton.cpp \
    buttons/numberbutton.cpp \
    buttons/unaryoperationbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    result_bar/resultbar.cpp \
    submenu/additionalcalculatorpanel.cpp \
    submenu/maincalculatorpanel.cpp \
    switcher/switcher.cpp

HEADERS += \
    buttons/binaryoperationbutton.h \
    buttons/clearbutton.h \
    buttons/dotbutton.h \
    buttons/equalbutton.h \
    buttons/numberbutton.h \
    buttons/unaryoperationbutton.h \
    mainwindow.h \
    result_bar/resultbar.h \
    submenu/additionalcalculatorpanel.h \
    submenu/maincalculatorpanel.h \
    switcher/switcher.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
