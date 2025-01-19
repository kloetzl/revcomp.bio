#include <stdlib.h>

/*

ff = "abcdghkmnrstuvwyABCDGHKMNRSTUVWY"
bb = "tvghcdmknysaabwrTVGHCDMKNYSAABWR"

comp = list(range(128))
for f, b in zip(ff, bb):
	comp[ord(f)] = ord(b)

print(json.dumps(comp))

*/

static const char comp[] = {
	0,	 1,	  2,   3,	4,	 5,	  6,   7,	8,	 9,	  10,  11,	12,	 13, 14,
	15,	 16,  17,  18,	19,	 20,  21,  22,	23,	 24,  25,  26,	27,	 28, 29,
	30,	 31,  32,  33,	34,	 35,  36,  37,	38,	 39,  40,  41,	42,	 43, 44,
	45,	 46,  47,  48,	49,	 50,  51,  52,	53,	 54,  55,  56,	57,	 58, 59,
	60,	 61,  62,  63,	64,	 84,  86,  71,	72,	 69,  70,  67,	68,	 73, 74,
	77,	 76,  75,  78,	79,	 80,  81,  89,	83,	 65,  65,  66,	87,	 88, 82,
	90,	 91,  92,  93,	94,	 95,  96,  116, 118, 103, 104, 101, 102, 99, 100,
	105, 106, 109, 108, 107, 110, 111, 112, 113, 121, 115, 97,	97,	 98, 119,
	120, 114, 122, 123, 124, 125, 126, 127};

char *revcomp(const char *begin, const char *end, char *dest)
{
	size_t length = end - begin;
	size_t index = length - 1;
	for (const char *ptr = begin; ptr != end; ptr++, index--) {
		unsigned char c = *ptr;
		char d = comp[c];
		dest[index] = d;
	}
	return dest + length;
}
