import collections


def part_1() -> None:
    data = tuple(
        (int((inner := line.split())[0]), int(inner[1]))
        for line in open("inputs/2024/day1.txt").readlines()
    )
    col1, col2 = sorted(x[0] for x in data), sorted(x[1] for x in data)
    print(sum(abs(x - y) for x, y in zip(col1, col2)))


def part_2() -> None:
    data = tuple(
        (int((inner := line.split())[0]), int(inner[1]))
        for line in open("inputs/2024/day1.txt").readlines()
    )
    col1, col2 = sorted(x[0] for x in data), sorted(x[1] for x in data)
    right_count = collections.Counter(col2)
    similarity_score = 0
    for number in col1:
        similarity_score += number * right_count[number]
    print(similarity_score)


main = lambda p: part_1() if p == 1 else part_2()
