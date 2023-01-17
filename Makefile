CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a: s21_math.c main.c
	$(CC) $(CFLAGS) s21_math.c main.c -o s21_math.a

test: s21_test.c 
	$(CC) $(CFLAGS) -lcheck -lm -lpthread s21_test.c s21_math.c -o test
	./test
	rm test

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage s21_test.c s21_math.c -pthread -lcheck -pthread -lm -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o test_html unit_test.info
	open test_html/index.html

clean:
	rm s21_math.a

rebuild: 
	clean all
