QT       += core gui 3dextras qml quick \
concurrent \
3dcore 3drender 3dinput \
3dquick 3dquickrender 3dquickinput 3dquickextras \
network quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += resources_big c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui \

OTHER_FILES += \
    *.qml \
    planets.js \
    shaders/gl3/*.* \
    shaders/es2/*.* \

RESOURCES += \
    planets-qml.qrc \
    planets-qml-images.qrc

DISTFILES += \
    PlanetsMain.qml \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
