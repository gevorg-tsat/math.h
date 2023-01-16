CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a: s21_math.c
	$(CC) $(CFLAGS) s21_math.c -o s21_math.a

test: s21_test.c 
	$(CC) $(CFLAGS) -lcheck -lm -lpthread s21_test.c s21_math.c -o test
	./test
	rm test

clean:
	rm s21_math.a

rebuild: 
	clean all
