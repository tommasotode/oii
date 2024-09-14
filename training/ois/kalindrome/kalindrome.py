#!/usr/bin/env python3

N = int(input().strip())
S = input().strip()


def check(k):
    if N % k != 0:
        return False

    i = 0
    while S[i : i + k] == S[-i - k : N - i]:
        i += k
        if i >= N // 2:
            return True

    return False


for k in range(1, N):
    if check(k):
        print(k)
        break
