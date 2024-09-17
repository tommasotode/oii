#!/usr/bin/env python3
import sys

# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N = int(input().strip())
P = list(map(int, input().strip().split()))
if P == sorted(P):
  print(0)
  exit()

min_index = min(range(len(P)), key=P.__getitem__)

i = (min_index+1) % N
while i != min_index:

  if P[(i + 1) % N] < P[i] and (i+1)%N != min_index:
    print(-1)
    exit()
  
  i = (i + 1) % N

print(N-min_index)

sys.stdout.close()