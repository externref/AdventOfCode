grid = [x.strip() for x in open("inputs/2024/day4.txt").readlines()]


def part_1() -> int:
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1)]
    target = "XMAS"
    rows = len(grid)
    cols = len(grid[0])
    count = 0

    def check_direction(row, col, dr, dc):
        for i in range(len(target)):
            r = row + i * dr
            c = col + i * dc
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] != target[i]:
                return False
        return True

    for row in range(rows):
        for col in range(cols):
            for dr, dc in directions:
                if check_direction(row, col, dr, dc):
                    count += 1

    return count


def part_2():
    rows = len(grid)
    cols = len(grid[0])

    directions = [
        (dx, dy) for dx in range(-1, 2) for dy in range(-1, 2) if dx != 0 or dy != 0
    ]

    def has_xmas(r, c):
        if not (1 <= r < rows - 1 and 1 <= c < cols - 1):
            return False
        if grid[r][c] != "A":
            return False

        diag_1 = f"{grid[r-1][c-1]}{grid[r+1][c+1]}"
        diag_2 = f"{grid[r-1][c+1]}{grid[r+1][c-1]}"

        return diag_1 in ["MS", "SM"] and diag_2 in ["MS", "SM"]

    return sum(has_xmas(r, c) for r in range(rows) for c in range(cols))


main = lambda part: part_1() if part == 1 else part_2()
