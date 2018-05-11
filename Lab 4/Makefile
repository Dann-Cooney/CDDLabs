
#Daniel Cooney
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES=Semaphore.h
CFILES=Barriers.cpp Semaphore.cpp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES)
	$(CC) -o Barriers $(CFLAGS) $(CFILES) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
rm *.o