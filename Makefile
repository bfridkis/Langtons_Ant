##################################################################
## Program name: Makefile
## Author: Benjamin Fridkis
## Date: 4/12/2017
## Description: Makefile for Project 1 (Langton's Ant Simulation)
##################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
#CXXFLAGS += Werror
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS+= -03
#LDFLAGS = -lboost_date_time

OBJS = Menu.o InputValidation.o Ant.o printBoard.o mainProject1.o  

SRCS = Menu.cpp InputValidation.cpp Ant.cpp printBoard.cpp mainProject1.cpp

HEADERS = Menu.hpp InputValidation.hpp Ant.hpp printBoard.hpp

mainProject1: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o mainProject1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm *.o mainProject1

