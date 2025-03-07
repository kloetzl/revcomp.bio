## Rust

The Rust implementation uses an iterator over the characters of the input
sequence, reverses that iterator (which is cheap since the Chars-iterator
is a DoubleEndedIterator), and translates char by char using the same
lookup table used in the C variant:

&&&& src/revcomp.rs

This iterator implementation is significantly faster than C-like implementations
that operate with indizes on input- and output-arrays. 

Contributed by: Manuel Landesfeind, 2025

