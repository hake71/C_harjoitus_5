CC= gcc
CFLAGS= -Wall -I.
EXE_NAME=Convert
FILES= valuutta.c
INCLUDE = 

all: $(FILES) $(INCLUDE)
	clear
	$(CC) -o $(EXE_NAME) $(FILES)  $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXE_NAME)
	
run:
	./$(EXE_NAME) 112.34 USD EUR

run2:
	./$(EXE_NAME) 112.34 EUR USD
run3:
	./$(EXE_NAME) 11s2.3S4 EUR US
	
rebuild: clean all

b1: clean all run

b2: clean all run2

b3: clean all run3
