CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a: s21_math.c
	$(CC) $(CFLAGS) s21_math.c -o s21_math.a

test: 
	$(CC) $(CFLAGS) -lcheck -lm -lpthread s21_test.c -o test
	./test
	rm test

clean:
	rm s21_math.a

rebuild: 
	clean all
