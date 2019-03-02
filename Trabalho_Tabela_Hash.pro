#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T19:54:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trabalho_Tabela_Hash
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        Hash.cpp \
        HashTable.cpp \
        HashTableLinked.cpp \
        Node.cpp \
        CountWord.cpp \
        HashTableArray.cpp \
        StringData.cpp \
        DlgVocabulary.cpp \
        GridWidget.cpp

HEADERS  += mainwindow.h \
        Hash.h \
        HashTable.h \
        HashTableLinked.h \
        Node.h \
        CountWord.h \
        HashTableArray.h \
        StringData.h \
        DlgVocabulary.h \
        sort.h \
        GridWidget.h

FORMS    += mainwindow.ui \
        DlgVocabulary.ui

RESOURCES += \
    icons.qrc
