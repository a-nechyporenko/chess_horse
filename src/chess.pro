TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Field.cpp \
    Board.cpp \
    Member.cpp \
    Intelligence.cpp \
    Horse.cpp \
    Step.cpp

HEADERS += \
    Field.hpp \
    Board.hpp \
    Member.hpp \
    Intelligence.hpp \
    Horse.hpp \
    Step.hpp
