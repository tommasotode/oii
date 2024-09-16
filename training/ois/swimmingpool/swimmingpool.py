#!/usr/bin/env python3
import statistics

N = int(input().strip())
P = list(map(int, input().strip().split()))

P.sort()

med1 = int(statistics.median_high(P))
m, nearestval1 = 10000000, 0
for i in P:
    if abs(med1 - i) <= m:
        m = abs(med1 - i)

        if max(i-P[0], P[-1]-i) < max(nearestval1-P[0], P[-1]-nearestval1):
            nearestval1 = i

med2 = int(statistics.median_low(P))
m, nearestval2 = 10000000, 0
for i in P:
    if abs(med1 - i) <= m:
        m = abs(med1 - i)

        if max(i-P[0], P[-1]-i) < max(nearestval2-P[0], P[-1]-nearestval2):
            nearestval2 = i

sol = min( max(nearestval1-P[0], P[-1]-nearestval1), max(nearestval2-P[0], P[-1]-nearestval2) )
print(sol)