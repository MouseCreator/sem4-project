QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    BinaryTree.cpp \
    Expression.cpp \
    formula.cpp \
    model.cpp \
    Graph.cpp \
    modelform.cpp \
    savedmodel.cpp \
    feature.cpp \
    variable.cpp \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    BinaryTree.h \
    Expression.h \
    formula.h \
    model.h \
    Graph.h \
    modelform.h \
    savedmodel.h \
    feature.h \
    variable.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui \
    modelform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
