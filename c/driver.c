#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char *revcomp(const char *begin, const char *end, char *dest);

struct test {
	const char *forward;
	const char *backward;
};

struct test parse_file(const char *path)
{
	FILE *file = fopen(path, "r");
	assert(file);
	char *line = malloc(9);
	size_t linecap = 9;
	ssize_t linelen = getline(&line, &linecap, file);

	assert(linelen >= 9);
	assert(strcmp(">forward\n", line) == 0);

	linelen = getline(&line, &linecap, file);
	assert(linelen >= 0);
	line[linelen - 1] = '\0';

	const char *forward = line;
	line = malloc(10);
	linecap = 10;
	linelen = getline(&line, &linecap, file);

	assert(linelen >= 10);
	assert(strcmp(">backward\n", line) == 0);

	linelen = getline(&line, &linecap, file);
	line[linelen - 1] = '\0';
	const char *backward = line;
	assert(linelen >= 0);
	fclose(file);

	return (struct test){forward, backward};
}

void check(const char *path)
{
	struct test test = parse_file(path);
	size_t len = strlen(test.forward);
	char *dest = malloc(len);
	revcomp(test.forward, test.forward + len, dest);
	if (strncmp(dest, test.backward, len) != 0) {
		printf("'%s' != '%s'\n", dest, test.backward);
		assert(0);
	}
}

int main()
{
	const char *testdir = "../test";
	char filepath[1024];
	snprintf(filepath, 1024, "%s/simple.fa", testdir);
	check(filepath);
}
