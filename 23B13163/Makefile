CC = gcc
CFLAGS = -g

SRC = xcc-small_extend.c
BIN = a.out

TEST1 = $(wildcard test1/t[1-6].c)
TEST2 = $(wildcard test2/t[1-5].c)
TESTS = $(TEST1) $(TEST2)

all: $(BIN) run-tests

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

run-tests: $(BIN)
	@for file in $(TESTS); do \
		echo "=== Running $$file ==="; \
		./$(BIN) $$file; \
		echo ""; \
	done

clean:
	rm -f $(BIN)
