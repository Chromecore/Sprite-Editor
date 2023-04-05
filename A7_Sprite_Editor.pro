QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickablelabel.cpp \
    editingsection.cpp \
    framelistsection.cpp \
    fullsizepreview.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    previewsection.cpp \
    toolsection.cpp

HEADERS += \
    clickablelabel.h \
    editingsection.h \
    framelistsection.h \
    fullsizepreview.h \
    mainwindow.h \
    model.h \
    previewsection.h \
    toolsection.h

FORMS += \
    editingsection.ui \
    framelistsection.ui \
    fullsizepreview.ui \
    mainwindow.ui \
    previewsection.ui \
    toolsection.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \
    Resources.qrc
