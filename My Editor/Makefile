CC = g++


output: main.o Editor.o Document.o
		$(CC) main.o Editor.o Document.o -o output

main.o: main.cpp
		$(CC) -c main.cpp

Editor.o: Editor.cpp
		$(CC) -c Editor.cpp

Document.o: Document.cpp
		$(CC) -c Document.cpp

clean:
	  rm *.o output
