## C

This implementation in C aims to be reasonably fast while supporting upper and lowercase for all standard IUPAC codes. Any non-IUPAC ascii character is left unchanged. It does not support UTF-8 encoded strings.

At the center of this method is the `comp` table containing the complement of single nucleotides. The contents was generated using the following Python script.

```Python
ff = "abcdghkmnrstuvwyABCDGHKMNRSTUVWY"
bb = "tvghcdmknysaabwrTVGHCDMKNYSAABWR"

comp = list(range(128))
for f, b in zip(ff, bb):
	comp[ord(f)] = ord(b)

print(json.dumps(comp))
```

This implementation reads the input in reverse and writes forward as that is faster on some CPUs than vice versa. For the destination we use `dest[index]` to avoid forming a pointer to the character preceeding `dest` which is undefined behavior according to the specification.

&&&& revcomp.c

Contributed by: Fabian Klötzl, 2025

