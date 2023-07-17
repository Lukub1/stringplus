CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror
GCOV=-fprofile-arcs -ftest-coverage

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
	CC += -D OS_LINUX -g -s
	CHECK_LEAKS=valgrind --leak-check=full --track-origins=yes --log-file=log.txt
else
	LINUX_LIBS=
	CC += -D OS_MAC
	CHECK_LEAKS=CK_FORK=no leaks --atExit --
	OPEN_GCOV=open coverage/index.html
endif

all: clean s21_string.a test gcov_report

s21_string.a: s21_string.o
	@ar -rcs s21_string.a s21_string.o
	@ranlib $@
	@cp $@ lib$@

test: s21_string_test.o s21_string.a
	@$(CC) s21_string_test.o s21_string.a -o Test -lcheck $(LINUX_LIBS)
	@./Test

gcov_report: s21_string.c s21_string_test.c s21_string.h
	@$(CC) s21_string_test.c s21_string.c -o Test -lcheck $(LINUX_LIBS) $(GCOV)
	@./Test
	@lcov -c -d . -o coverage.info
	@genhtml coverage.info -o coverage
	@$(OPEN_GCOV)

s21_string.o: s21_string.c s21_string.h
	@$(CC) $(CFLAGS) s21_string.c

s21_string_test.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) s21_string_test.c

clean:
	@rm -rf *.o *.a *.out *.txt *.gcno *.gch *.gcda *.info coverage Test

check: clean s21_string.a
	@cppcheck s21_string.c s21_string.h s21_string_test.c s21_string_test.h
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extension=c s21_string.c s21_string.h s21_string_test.c s21_string_test.h
	@$(CC) s21_string_test.c s21_string.a -lcheck $(LINUX_LIBS) -o ./Test
	@$(CHECK_LEAKS) ./Test
	@rm CPPLINT.cfg *.o *.a
	
rebuild: clean all