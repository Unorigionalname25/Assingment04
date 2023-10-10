CC = gcc
OBJECTS = asgn4.o
FLAGS = -std=c11
SOURCE = $(wildcard *.c)

asgn4: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o asgn4 -lm -fno-pie -no-pie

%.o: %.c
	$(CC) -c $^

run: asgn4
	./asgn4

echo:
	echo $(SOURCE)

clean:
	rm -f *.o asgn4