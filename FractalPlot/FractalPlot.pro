TEMPLATE = app

SOURCES += main.cpp \
    game.cpp

HEADERS += \
    game.h \

CONFIG += c++11

LIBS += -L"/usr/loca/lib"

#------------------------------------------
##Add these lines for SFML:

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/loca/include"
DEPENDPATH += "/usr/loca/include"

