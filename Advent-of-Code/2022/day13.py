import sys
from functools import cmp_to_key

def compare(a, b):
    match a, b:
        case int(), int():
            return a - b
        case list(), list():
            for x, y in zip(a, b):
                if c := compare(x, y):
                    return c
            return compare(len(a), len(b))
        case list(), int():
            return compare(a, [b])
        case int(), list():
            return compare([a], b)

def part1(pairs):
    res = 0
    for i in range(len(pairs)):
        if compare(pairs[i][0], pairs[i][1]) < 0:
            res += i + 1 
    print(res)
    
def part2(packets):
    packets.append([])
    packets.append([2])
    packets.append([6])
    sorted_packets = sorted(packets, key=cmp_to_key(compare))
    res = sorted_packets.index([2]) * sorted_packets.index([6])
    print(res)
    
# read input
pairs = []
packets = []
lines = sys.stdin.readlines()
n = len(lines)
for i in range(0, n, 3):
    a = eval(lines[i])
    b = eval(lines[i+1])
    pairs.append((a, b))
    packets.append(a)
    packets.append(b)

part1(pairs)
part2(packets)
