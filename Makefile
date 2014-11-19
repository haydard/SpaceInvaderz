

game : main.o eventHandler.o gametick.o renderer.o
	gcc -o game main.o eventhandler.o gametick.o renderer.o 

main.o : main.c Includes/gametick.h
	gcc -c main.c

gametick.o : Game/gametick.c Includes/objects.h
	gcc -c Game/gametick.c

eventHandler.o : Game/eventHandler.c
	gcc -c Game/eventHandler.c

objects.o : Game/objects.c 
	gcc -c Game/objects.c

renderer.o : Game/renderer.o Includes/gametick.h
	gcc -c Game/renderer.c

clean: rm game 



