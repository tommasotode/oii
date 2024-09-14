#!/usr/bin/env python3

def solve(A, B):
    if A > 0:
        return "+"

    if B >= 0:
        return "0"

    if (abs(B) - abs(A) + 1) % 2 == 0:
        return "+"
    else:
        return "-"


T = int(input().strip())
for i in range(T):
    A, B = map(int, input().strip().split())
    print(solve(A, B))
