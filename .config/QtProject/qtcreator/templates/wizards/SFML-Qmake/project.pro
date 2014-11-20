TEMPLATE = app
CONFIG += console

SOURCES += main.%CppSourceSuffix%




CONFIG += c++11

# Adjust your library that contains libsfml*
LIBS += -L"/usr/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

# Adjust your library that contains folder SFML
INCLUDEPATH += "/usr/include"
DEPENDPATH += "/usr/include"
