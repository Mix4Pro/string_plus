CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDLIBS = 
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage -lgcov



SOURCES = s21_string.c s21_sscanf.c s21_sprintf.c
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = s21_string.a

TEST_DIR = tests
TEST_SOURCES = ${wildcard ${TEST_DIR}/*/*.c}
TEST_SUITE_SOURCES = $(wildcard $(TEST_DIR)/*/*_suite.c)
TEST_SUITE_OBJECTS = $(patsubst %.c,%.o,$(TEST_SUITE_SOURCES))
TEST_EXECUTABLES = $(patsubst %.c,%,$(TEST_SUITE_SOURCES))
ALL_SRC = $(wildcard *.c */*.c */*/*.c *.h */*.h */*/*.h)

.PHONY: all clean test clang control cppcheck

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

$(TEST_EXECUTABLES): LDLIBS = -lcheck -lm -lsubunit -lrt -lpthread
$(TEST_EXECUTABLES): %: %.o $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $< $(LIBRARY) $(LDLIBS)

test: clean $(LIBRARY) $(TEST_EXECUTABLES)
	for test in $(TEST_EXECUTABLES); do ./$$test; done

clean:
	rm -f $(LIBRARY) $(TEST_SUITE_OBJECTS) $(TEST_EXECUTABLES) *.o **/*.o tests/main
	rm -f *.gcno *.gcda *.gcov **/**/*.gcno **/**/*.gcda **/**/*.gcov coverage.info -r coverage_report
	rm -rf gcov_report

clang_check:
	clang-format -n ${SOURCES}
	clang-format -n ${TEST_SOURCES}

clang_fix:
	clang-format -i ${SOURCES}
	clang-format -i ${TEST_SOURCES}

coverage: CFLAGS += $(GCOV_FLAGS)
coverage: LDLIBS += $(GCOV_FLAGS)
coverage: clean $(LIBRARY) $(TEST_EXECUTABLES)
	for test in $(TEST_EXECUTABLES); do ./$$test; done

gcov_report: coverage
	lcov --capture --directory . --output-file coverage.info
	mkdir -p gcov_report
	genhtml coverage.info --output-directory gcov_report



control: CFLAGS += -DVALGRIND
control: clean $(LIBRARY) $(TEST_EXECUTABLES)
	for test in $(TEST_EXECUTABLES); do CK_FORK=no valgrind --tool=memcheck --leak-check=yes ./$$test; done