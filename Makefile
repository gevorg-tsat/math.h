CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a: s21_math.c main.c
	$(CC) $(CFLAGS) s21_math.c main.c -o s21_math.a

test: s21_test.c 
	$(CC) $(CFLAGS) -lcheck -lm -lpthread s21_test.c s21_math.c -o test
	./test
	rm test

gcov_report: test
	lcov --capture --directory test -o gcov_report.info -c -d .
	genhtml -o gcov_report gcov_report.info
	open gcov_report/index.html

clean:
	rm s21_math.a

rebuild: 
	clean all
