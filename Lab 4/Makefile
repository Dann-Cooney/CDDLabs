CC=g++
CFLAGS= -std=c++11 -pthread
FILES= Barriers.cpp Semaphore.cpp
OUT_EXE=Barriers

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *-o
debug:
	gdb
