CC=gcc
CFLAGS=-c -fPIC
LDFLAGS=-shared -lm
SRC_DIR=src
LIB_DIR=lib
TEST_DIR=test
SORT_OBJ=psort.o pinsort.o prsort.o
MATH_OBJ=pabs.o pcordic.o psqrt.o
UTIL_OBJ=prand.o psearch.o pstring.o
DATA_OBJ=pmatrix.o
OBJ=$(SORT_OBJ) $(MATH_OBJ) $(UTIL_OBJ) $(DATA_OBJ)

TESTS=psort_test.e pmath_test.e putil_test.e pdata_test.e

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

all: $(patsubst %,$(SRC_DIR)/%,$(OBJ))
	$(CC) -o $(LIB_DIR)/libpalgo.so $(SRC_DIR)/*.o $(LDFLAGS)

check: all test


%.e: %.c
	@export LD_LIBRARY_PATH=$(pwd)/$(LIB_DIR)
	$(CC) -Iinclude -L$(LIB_DIR) -o $@ $< -lpalgo
	@./$@ > $*.cmp
	@diff -q $*.cmp $*.out >/dev/null || (echo "Test $@ failed" && exit 1)
	@unset LD_LIBRARY_PATH

test: $(patsubst %,$(TEST_DIR)/%,$(TESTS))
	@rm -f test/*.cmp
	@rm -f test/*.e

clean:
	@rm -f $(SRC_DIR)/*.o
	@rm -f test/*.e
	@rm -f test/*.cmp
