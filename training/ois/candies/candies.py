#!/usr/bin/env python3
import sys

N = int(input().strip())
S = list(map(int, input().strip().split()))
S.sort()

s = 1
sum = 0
for i in range(len(S)-1):
  sum += s
  if S[i] != S[i+1]:
    s += 1

sum+=s
print(sum)