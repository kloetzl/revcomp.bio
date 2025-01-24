import itertools


def cat(path: str) -> [str]:
    with open(path, "r") as file:
        yield from file


def print_language(language: str) -> [str]:
    description = f"{language}/description.md"
    for line in cat(description):
        if line.startswith("&&&&"):
            implementation = f"{language}/{line.split()[1]}"
            yield from cat(implementation)
        else:
            yield line


def main():
    languages = ["c", "python"]
    structure = [
        cat("web/header.md"),
        *(print_language(language) for language in languages),
        cat("web/footer.md"),
    ]
    print("".join(itertools.chain.from_iterable(structure)))


if __name__ == "__main__":
    main()
