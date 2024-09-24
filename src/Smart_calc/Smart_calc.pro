QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../s21_PRN.c \
    ../s21_credit.c \
    ../s21_deposit.c \
    ../s21_smart_calc.c \
    ../s21_stack.c \
    creditcalc.cpp \
    depositcalc.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    smartcalc.cpp

HEADERS += \
    creditcalc.h \
    depositcalc.h \
    mainwindow.h \
    qcustomplot.h \
    smartcalc.h \
    ../s21_calc.h

FORMS += \
    creditcalc.ui \
    depositcalc.ui \
    mainwindow.ui \
    smartcalc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
