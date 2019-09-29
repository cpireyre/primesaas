src := primes.c random.c main.c
name :=	prime
all:
	$(CC) $(CFLAGS) $(src) -o $(name)

clean:
	$(RM) $(name)
