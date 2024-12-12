import re


def mul_lexer(data: str) -> int:
    pattern = r"mul\((\d+),(\d+)\)"
    total_sum = 0
    matches = re.findall(pattern, data)

    for match in matches:
        x, y = int(match[0]), int(match[1])
        total_sum += x * y

    return total_sum


def mul_do_dont_lexer(data: str) -> int:
    mul_enabled = True
    total_sum = 0

    pattern = r"mul\((\d+),(\d+)\)|do\(\)|don't\(\)"
    for match in re.finditer(pattern, data):
        if match.group(0) == "do()":
            mul_enabled = True
        elif match.group(0) == "don't()":
            mul_enabled = False
        elif match.group(0).startswith("mul"):
            num1 = int(match.group(1))
            num2 = int(match.group(2))
            if mul_enabled:
                total_sum += num1 * num2

    return total_sum


data = open("inputs/2024/day3.txt").read()
main = lambda part: mul_lexer(data) if part == 1 else mul_do_dont_lexer(data)
