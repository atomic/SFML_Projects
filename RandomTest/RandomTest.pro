TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

SOURCES += main.cpp

#------------------------------------------
##Add these lines for SFML:

CONFIG += c++11


LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"
#-----------------------------------------

include(deployment.pri)
qtcAddDeployment()
