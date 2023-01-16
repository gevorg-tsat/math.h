CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a: s21_math.c
	$(CC) $(CFLAGS) s21_math.c -o s21_math.a

clean:
	rm s21_math.a
