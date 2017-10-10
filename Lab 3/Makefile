CC=g++
CFLAGS= -std=c++11 -pthread
FILES= MutalExclusion.cpp Semaphore.cpp
OUT_EXE=MutalExclusion

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *-o
debug:
	gdb

