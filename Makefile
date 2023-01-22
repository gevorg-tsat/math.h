CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_math.a

s21_math.a:
	$(CC) -c s21_math.c -o s21_math.o
	ar rcs s21_math.a *.o
	ranlib s21_math.a
	rm *.o

test: s21_math.a
	$(CC) $(CFLAGS) -lcheck -lm -lpthread s21_test.c s21_math.a -o test
	./test
	rm test

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage s21_test.c s21_math.c -pthread -lcheck -pthread -lm -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o test_html unit_test.info
	open test_html/index.html

clean:
	rm -rf s21_math.a *.gc* test unit_test.info test_html/

rebuild: 
	clean all
