reports = [
    (lambda line: [int(x) for x in line.split()])(line)
    for line in (open("inputs/day2.txt")).readlines()
]

def verify_v1(report: list[int]) -> bool:
    if not (
        all(report[i] < report[i + 1] for i in range(len(report) - 1))
        or all(report[i] > report[i + 1] for i in range(len(report) - 1))
    ):
        return False
    for i in range(len(report) - 1):
        if abs(report[i] - report[i + 1]) < 1 or abs(report[i] - report[i + 1]) > 3:
            return False

    return True

def verify_v2(report: list[int]) -> bool:
    if verify_v1(report):
        return True
    for i in range(len(report)):
        new_report = report[:i] + report[i+1:]
        if verify_v1(new_report):
            return True
    return False


print(sum(verify_v2(report) for report in reports))
