CC = gcc
CFLAGS = -g -Wall
TARGETS = hwmain
OBJECTS = hwmain.c crud.o
.SUFFIXES = .c .o

$(TARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS)  -o $@ $^
.c.o :
	$(CC) $(CFLAGS)  -c $<
main_debug : hwmain.c debug_crud.o
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
debug_crud.o :
	$(CC) $(CFALGS) -DDEBUG -c crud.c -o debug_crud.o
clean : 
	rm *.o $(TARGETS) main_debug
