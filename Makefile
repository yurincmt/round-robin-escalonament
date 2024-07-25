SRCDIR := src
SOURCES := $(shell find $(SRCDIR) -name '*.c')
BIN := bin/exec
INPUT := data/input.txt

build: $(SOURCES)
	cc $(SOURCES) -o $(BIN)

test:
	./$(BIN) < $(INPUT)

clean: $(BIN)
	rm -rf $(BIN)