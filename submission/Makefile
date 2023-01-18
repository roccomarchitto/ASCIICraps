CC=g++
PROG=diceprogram
ARGS=-I.

run: $(PROG)
	./$(PROG)

diceprogram: main.cpp Dice.cpp
	$(CC) -o $(PROG) main.cpp Dice.cpp $(ARGS)

.PHONY: run