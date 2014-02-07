CC = g++#g++-4.8
INCLUDE = -I/usr/local/include/SDL2 -I/usr/include/GL
LIB = -L/usr/local/lib -lSDL2 -lGL -lGLEW

bouncingballs: balls.o shaderutils.o
	$(CC) *.o -g -o bouncingballs $(LIB) -Wl,-rpath=/usr/local/lib

balls.o:
	$(CC) balls.cpp -c -g $(INCLUDE)

shaderutils.o:
	$(CC) shaderutils.cpp -c -g $(INCLUDE)

clean:
	rm -f bouncingballs
	rm -f *.o
