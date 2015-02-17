TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += c++11

SOURCES += main.cpp \
    game.cpp

HEADERS += \
    game.h \


LIBS += -L"/usr/loca/lib"

#------------------------------------------
##Add these lines for SFML:

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/loca/include"
DEPENDPATH += "/usr/loca/include"
