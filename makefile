# target: dependencies
# 	action  

.PHONY: clean all
CFLAGS = -Wall -g -O2
targets = hello world
sources = main.c message.c
objects = main.o message.o

# hello: main.c message.c
# 	gcc main.c message.c -o hello

all: $(targets)
	@echo "all done"

# hello: main.o message.o
# 	gcc main.o message.o -o hello

# world: main.o message.o
# 	gcc main.o message.o -o world

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

# main.o: main.c
# 	gcc $(CFLAGS) -c main.c

# main.o: main.c
# 	gcc $(CFLAGS) -c $< -o $@

# message.o: message.c
# 	gcc $(CFLAGS) -c message.c

# message.o: message.c
# 	gcc $(CFLAGS) -c $< -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o hello world