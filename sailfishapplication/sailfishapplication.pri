include(../globals.pri)

QT += declarative

SOURCES += $$PWD/sailfishapplication.cpp
HEADERS += $$PWD/sailfishapplication.h
INCLUDEPATH += $$PWD

target.path = $$BINDIR

qml.path = $$SHAREDIR/qml
desktop.path = $$APPLICATIONSDIR
icons.path = $$SHAREDIR/icons

contains(CONFIG, desktop) {
    DEFINES *= DESKTOP
    QT += opengl
}

INSTALLS += target qml desktop icons

DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${SHAREDIR}/qml/\"\\\"\"

CONFIG += link_pkgconfig
packagesExist(qdeclarative-boostable) {
    message("Building with qdeclarative-boostable support")
    DEFINES += HAS_BOOSTER
    PKGCONFIG += qdeclarative-boostable
} else {
    warning("qdeclarative-boostable not available; startup times will be slower")
}




