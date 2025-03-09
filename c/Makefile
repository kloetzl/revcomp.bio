
.PHONY: all build check clean format

all: build check

build: driver

driver: revcomp.c driver.c
	$(CC) -O2 -std=c11 -D_GNU_SOURCE -Wall -Wextra -o $@ $^

check: driver
	./driver

format:
	clang-format -i driver.c revcomp.c

clean:
	$(RM) driver
