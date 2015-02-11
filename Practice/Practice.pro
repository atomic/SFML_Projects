TEMPLATE = app
#CONFIG -= console
SOURCES += main.cpp
CONFIG += c++11

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release):   LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

