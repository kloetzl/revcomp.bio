
.PHONY: all build check clean print

all: build check

build: driver

driver: revcomp.c driver.c
	$(CC) -O2 -std=c11 -Wall -Wextra -o $@ $^

check: driver
	./driver

print:
	@ echo '```C'
	@ cat revcomp.c
	@ echo '```'

clean:
	$(RM) driver
