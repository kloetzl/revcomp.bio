comp = str.maketrans(
    "abcdghkmnrstuvwyABCDGHKMNRSTUVWY", "tvghcdmknysaabwrTVGHCDMKNYSAABWR"
)


def revcomp(seq: str) -> str:
    return seq[::-1].translate(comp)
