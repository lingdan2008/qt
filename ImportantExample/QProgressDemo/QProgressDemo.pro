######################################################################
# Automatically generated by qmake (3.1) Sun Aug 12 21:04:09 2018
######################################################################

TEMPLATE = app
TARGET = QProgressDemo
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += qprog.h \
           qprogplugin.h \
           Demo/dialog.h \
           Demo/qprog.h \
           src/commandparser.h \
           src/getopt.h \
           src/msgdef.h \
           src/option.h \
           src/qcounterthread.h \
           src/qop.h \
           src/QOutParser.h \
           src/qtcompat.h \
           src/Types.h \
           src/version.h \
           src/algorithm/zconf.h \
           src/algorithm/zlib.h \
           src/algorithm/zlib_alg.h \
           src/gui/ezprogressdialog.h \
           src/gui/ezprogressdialog_p.h \
           src/qarchive/arcreader.h \
           src/qarchive/qarchive.h \
           src/qarchive/qarchive_p.h \
           src/utils/convert.h \
           src/utils/qt_util.h \
           src/utils/strutil.h \
           src/utils/util.h \
           src/qarchive/gzip/GzipHeader.h \
           src/qarchive/gzip/GzipItem.h \
           src/qarchive/tar/qtar.h \
           src/qarchive/tar/TarHeader.h \
           src/qarchive/tar/TarItem.h \
           src/qarchive/zip/ZipHeader.h
FORMS += Demo/dialog.ui
SOURCES += qprog.cpp \
           qprogplugin.cpp \
           Demo/dialog.cpp \
           Demo/main.cpp \
           src/commandparser.cpp \
           src/getopt.cpp \
           src/main.cpp \
           src/option.cpp \
           src/qcounterthread.cpp \
           src/qop.cpp \
           src/QOutParser.cpp \
           src/algorithm/zlib_alg.cpp \
           src/gui/ezprogressdialog.cpp \
           src/qarchive/arcreader.cpp \
           src/qarchive/qarchive.cpp \
           src/utils/convert.cpp \
           src/utils/qt_util.cpp \
           src/utils/strutil.cpp \
           src/utils/util.cpp \
           src/qarchive/gzip/GzipItem.cpp \
           src/qarchive/tar/qtar.cpp \
           src/qarchive/zip/ZipHeader.cpp
RESOURCES += qprog.qrc
TRANSLATIONS += i18n/qop_zh-cn.ts
