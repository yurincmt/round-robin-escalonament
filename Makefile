# $@
# $<
# $^

C_SOURCE = $(wildcard ./src/*.c)

H_SOURCE = $(wildcard ./src*.h)

OBJ = $(C_SOURCE:.c=.o)


#
# Compilation and Linking
#
build: roundrobin

roundrobin: $(OBJ)
	gcc -o $@ $^
	rm -rf $^

./src/main.o: ./src/main.c $(H_SOURCE)
	gcc -o $@ $< -c

./src/priorityQueue.o: ./src/priorityQueue.c $(H_SOURCE)
	gcc -o $@ $< -c

./src/processQueue.o: ./src/processQueue.c $(H_SOURCE)
	gcc -o $@ $< -c


test: ./data/example.txt
	./roundrobin < ./data/example.txt

