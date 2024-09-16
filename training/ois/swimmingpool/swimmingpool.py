#!/usr/bin/env python3
import statistics

N = int(input().strip())
P = list(map(int, input().strip().split()))
P.sort()

m = 10000000
for i in P:
    m = min(m, max(i-P[0], P[-1]-i))
        
print(m)