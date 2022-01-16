QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar_window.cpp \
    event.cpp \
    eventgroup.cpp \
    group.cpp \
    main.cpp \
    note.cpp \
    notegroup.cpp \
    notes_window.cpp \
    task.cpp \
    taskgroup.cpp \
    tasks_window.cpp

HEADERS += \
    calendar_window.h \
    event.h \
    eventgroup.h \
    group.h \
    note.h \
    notegroup.h \
    notes_window.h \
    task.h \
    taskgroup.h \
    tasks_window.h

FORMS += \
    calendar_window.ui \
    notes_window.ui \
    tasks_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
