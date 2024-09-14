#!/usr/bin/env python3

N1, N2 = list(map(int, input().strip().split()))
a = set(list(map(int, input().strip().split())))
b = set(list(map(int, input().strip().split())))


s = 0
for i in b:
  if i in a:
    s += 1

print(s)