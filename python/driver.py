import revcomp
import glob


def parse_file(path: str) -> (str, str):
    with open(path, "r") as file:
        lines = [line.strip() for line in file.readlines()]
        assert lines[0] == ">forward", f"{path}: failed to parse file"
        assert lines[2] == ">backward", f"{path}: failed to parse file"
        return (lines[1], lines[3])


def main():
    tests = glob.glob("../test/*fa")
    for test in tests:
        forward, backward = parse_file(test)
        rc = revcomp.revcomp(forward)
        assert rc == backward, f"{rc} != {backward}"


if __name__ == "__main__":
    main()
