
.PHONY: all build check clean print format

all: build check

build: driver

driver: revcomp.c driver.c
	$(CC) -O2 -std=c11 -Wall -Wextra -o $@ $^

check: driver
	./driver

format:
	clang-format -i driver.c revcomp.c

clean:
	$(RM) driver
