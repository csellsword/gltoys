CC = g++-4.8
INCLUDE = -I/usr/local/include/SDL2 -I/usr/include/GL
LIB = -L/usr/local/lib -lSDL2 -lGL -lGLEW

bouncingballs:
	$(CC) balls.cpp -o bouncingballs $(INCLUDE) $(LIB) -Wl,-rpath=/usr/local/lib

clean:
	rm -f bouncingballs
	rm -f *.o
