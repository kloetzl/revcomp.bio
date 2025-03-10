mod revcomp;
pub use revcomp::*;

use std::io::BufRead;

// A simple struct to contain the test case
struct Case {
    fwd: String,
    rev: String,
}

fn read_file<P: AsRef<std::path::Path>>(path: P) -> std::io::Result<Case> {
    let mut fwd = String::new();
    let mut rev = String::new();
    let mut fh = std::fs::File::open(path).map(std::io::BufReader::new)?;

    assert_eq!(fh.read_line(&mut fwd)?, 9);
    assert_eq!(fwd, ">forward\n");
    fwd.clear();
    assert!(fh.read_line(&mut fwd)? > 0);
    assert_eq!(fwd.pop(), Some('\n'));

    assert_eq!(fh.read_line(&mut rev)?, 10);
    assert_eq!(rev, ">backward\n");
    rev.clear();
    assert!(fh.read_line(&mut rev)? > 0);
    assert_eq!(rev.pop(), Some('\n'));

    Ok(Case { fwd, rev })
}

fn main() {
    // Read the test file
    let case = read_file("../test/iupac.fa").expect("Cannot read test file");

    // Translate and check
    let translated = revcomp(&case.fwd);
    assert_eq!(translated, case.rev);
}
