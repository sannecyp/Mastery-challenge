CXX = g++
CXXFLAGS = -std=c++0x
OBJS = final.o 
SRCS = final.cpp
HEADERS = final.h

map: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o final 

