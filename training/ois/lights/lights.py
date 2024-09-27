#!/usr/bin/env python3
import sys

N, C = map(int, input().strip().split())
L = list(map(int, input().strip().split()))

count = C
while count < N:
  i = 0
  while i < N-count:
    s = set()
    s.update(L[i:i+count])
    if len(s) == C:
      print(count)
      exit()
    i+=1
  count += 1

if count == N:
  print(count)