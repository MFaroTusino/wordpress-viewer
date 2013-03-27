# The name of your app
TARGET = wordpress-viewer
QT += network

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += link_pkgconfig
    PKGCONFIG += QJson
}

# C++ sources
SOURCES += main.cpp \
    author.cpp \
    post.cpp \
    sharedobjectspool.cpp \
    postmodel.cpp \
    posthelper.cpp \

# C++ headers
HEADERS += \
    jsonhelper_p.h \
    datetimeformat_p.h \
    author.h \
    post.h \
    sharedobjectspool.h \
    postmodel.h \
    posthelper.h \

# QML files and folders
qml.files = *.qml pages cover main.qml

# Launcher files
launchers.files = data/jollafr/wordpress-viewer-jollafr \
                    data/utp/wordpress-viewer-utp \

# .desktop files
desktop.files = data/jollafr/wordpress-viewer-jollafr.desktop \
                data/utp/wordpress-viewer-utp.desktop \

# Icon files
icons.files = data/jollafr/jollafr.png \
                data/utp/utp.png

# Please do not modify the following line.
include(sailfishapplication/sailfishapplication.pri)

OTHER_FILES = \
    rpm/wordpress-viewer.yaml \
    data/jollafr/jollafr.png \
    data/jollafr/wordpress-viewer-jollafr.desktop \
    data/jollafr/wordpress-viewer-jollafr \
    data/utp/utp.png \
    data/utp/wordpress-viewer-utp.desktop \
    data/utp/wordpress-viewer-utp \
    pages/About.qml \
    pages/Changelog.qml \
    pages/ContactUs.qml \
    pages/Index.qml \
    pages/Search.qml \
    pages/PostPage.qml \
