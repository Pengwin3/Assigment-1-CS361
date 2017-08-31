MAINPROG=assignment01
CC=gcc
CXX=g++
CPPFLAGS=-g -std=c++11
LFLAGS=
CFLAGS=-g
TARGET=$(MAINPROG)
CPPS=$(wildcard *.cpp)
LINK=g++ $(CPPFLAGS)
OBJS=$(CPPS:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -MMD -o $@ -c $*.cpp


all: $(TARGET)  



$(TARGET): $(OBJS)
	$(LINK) $(FLAGS) -o $(TARGET) $^ $(LFLAGS)

clean:
	-/bin/rm -rf *.d *.o $(TARGET)
