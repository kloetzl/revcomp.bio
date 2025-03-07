use criterion::{criterion_group, criterion_main, Criterion};
use revcomp::*;
use std::hint::black_box;

pub fn revcomp_array_unsafe(fwd: &[u8]) -> Vec<u8> {
    let length = fwd.len();
    let mut dest = vec![0u8; length];

    unsafe {
        for index in 0..length {
            *dest.get_unchecked_mut(length - index - 1) =
                *revcomp::COMPLEMENT.get_unchecked(*fwd.get_unchecked(index) as usize);
        }
    }

    return dest;
}

fn bench_variants(c: &mut Criterion) {
    let mut group = c.benchmark_group("revcomp");
    group.bench_function("iterator", |b| {
        b.iter(|| revcomp_iter(black_box("abcdghkmnrstuvwyABCDGHKMNRSTUVWY".as_bytes())))
    });

    group.bench_function("array", |b| {
        b.iter(|| revcomp_array(black_box("abcdghkmnrstuvwyABCDGHKMNRSTUVWY".as_bytes())))
    });

    group.bench_function("unsafe", |b| {
        b.iter(|| revcomp_array_unsafe(black_box("abcdghkmnrstuvwyABCDGHKMNRSTUVWY".as_bytes())))
    });

    group.finish();
}

criterion_group!(benches, bench_variants);
criterion_main!(benches);
