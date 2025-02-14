## Python

Python has a built-in mechanisim for [exchanging characters in a string](https://docs.python.org/3/library/stdtypes.html#str.translate). It consists of one call to `str.maketrans` to build a table and then `.translate()` to apply it to a specific string. Together with a reverse slice `[::-1]` the resulting code is concise and efficient.

&&&& revcomp.py

Contributed by: Fabian Klötzl, 2025
