TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


LIBS += -L"/usr/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/include"
DEPENDPATH += "/usr/include"

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

