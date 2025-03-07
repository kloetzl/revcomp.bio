## Rust

Two different implementations are provided for Rust:

 - `revcmp_array` is a direct adoption of the revcomp C variant
 - `revcomp_iter` is an idiomatic variant that uses iterators to iterate the array in reverse order, translate and then collect into the result vector.

&&&& src/lib.rs

Interestingly, the idiomatic variant using the iterator is significantly faster than the array-variant. This also 
holds when benchmarked against an unsafe variant of the array version that omits array-bound checks. Run
`cargo bench` run the benchmarks. 

Contributed by: Manuel Landesfeind, 2025

