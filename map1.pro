QT += core gui
QT += network
QT += qml quick
QT += positioning
QT += location
QT       +=  quickcontrols2 quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#INCLUDEPATH += "C:\msys64\home\Moon\vcpkg\installed\x64-mingw-dynamic\include"  #тут хедеры proj'a
#LIBS += -L"C:\msys64\home\Moon\vcpkg\installed\x64-mingw-dynamic\bin" -lproj #ликовка слибой
INCLUDEPATH = /usr/local/include
LIBS = -L/usr/local/lib -lproj

include(../lib/lib.pri)

SOURCES += \
    demoitem.cpp \
    main.cpp \
    mainwindow.cpp \
    qgeowid/background.cpp \
    qgeowid/customtiles.cpp \
    qgeowid/ellipse.cpp \
    qgeowid/flags.cpp \
    qgeowid/items.cpp \
    qgeowid/mouse.cpp \
    qgeowid/mytile.cpp \
    qgeowid/mytiles.cpp \
    qgeowid/placemark.cpp \
    qgeowid/rectangle.cpp \
    qgeowid/tringle.cpp \
    qgeowid/utilities.cpp \
    qgeowid/waveanimation.cpp \
    qgeowid/widgets.cpp \
    selectordialog.cpp

HEADERS += \
    demoitem.h \
    mainwindow.h \
    qgeowid/background.h \
    qgeowid/customtiles.h \
    qgeowid/ellipse.h \
    qgeowid/flags.h \
    qgeowid/items.h \
    qgeowid/mouse.h \
    qgeowid/mytile.h \
    qgeowid/mytiles.h \
    qgeowid/placemark.h \
    qgeowid/rectangle.h \
    qgeowid/tringle.h \
    qgeowid/utilities.h \
    qgeowid/waveanimation.h \
    qgeowid/widgets.h \
    selectordialog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc

SUBDIRS += \
    ../lib/lib.pro \
    ../lib/lib.pro \
    ../lib/lib.pro

DISTFILES += \
    pictures/1l.png \
    pictures/21.png \
    pictures/2791085.jpg \
    pictures/6085900.jpg \
    pictures/7629044.jpg \
    pictures/7629161.jpg \
    pictures/7629165.jpg \
    pictures/7748.jpg \
    pictures/AbsentPairTraceNmbr.png \
    pictures/Analyze.png \
    pictures/AutoPlanningRange.png \
    pictures/CombatDisable.png \
    pictures/CombatDisableHLCP.png \
    pictures/CoordinateFailure.png \
    pictures/FUT100.png \
    pictures/FUT20.png \
    pictures/FUT40.png \
    pictures/FUT60.png \
    pictures/FUT80.png \
    pictures/FireFriend.png \
    pictures/FriendlyTarget.png \
    pictures/IPNotInSecureSector.png \
    pictures/LaunchDisable.png \
    pictures/LaunchDisableHLCP.png \
    pictures/NeighborActing.png \
    pictures/NoFreeFC.png \
    pictures/NoInZone.png \
    pictures/NoPairMFRLCH.png \
    pictures/NoReadyLCH.png \
    pictures/NoReadyMFR.png \
    pictures/Priority.png \
    pictures/RLRT_Interception.png \
    pictures/RLRT_Missing.png \
    pictures/TargetFriend.png \
    pictures/TargetInWork.png \
    pictures/TargetIsNotDetected.png \
    pictures/TargetJam.png \
    pictures/UnknownError.png


