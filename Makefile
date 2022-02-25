CC=gcc -g
CFLAGS=-I.
DEPS = 
OBJ = main.o sig.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SignalAnalysis.a: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm

clean:
	$(RM) *.o *.so* *.a

