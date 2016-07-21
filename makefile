#makefile for "c/s Server"
CC = g++
CFLAGS = -c -Wall -std=c++11

ALL: bin/ssmanager
	

bin/ssmanager: main.o jsoncpp.o portManager.o
	$(CC) -o bin/ssmanager main.o jsoncpp.o portManager.o 

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

jsoncpp.o: jsoncpp.cpp
	$(CC) $(CFLAGS) jsoncpp.cpp

portManager.o: portManager.cpp
	$(CC) $(CFLAGS) portManager.cpp

clean:
	rm -rf *o bin/ssmanager

#END
