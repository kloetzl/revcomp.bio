# Revcomp.bio

This project aims to be the definitive guide to computing the reverse complement of a genomic sequence. We collect implementations in many different programming languages and note tradeoffs for different approaches.

## Contributing

We are always happy to accept proposals for implementations in other languages. Here are some technical and non-technical guidelines.

- Use a common code formatter. For instance `ruff` and `clang-format` are used to format Python and C/C++ code, respectively.
- Reading the input string in reverse and writing forward is faster on some CPUs than the other way round.
- Using a lookup table will be about eight times faster than chaining if-elses.

## License

All code, data, and files in this project are released to the public domain. This means you are free to copy the code into your project verbatim without any consequences.
