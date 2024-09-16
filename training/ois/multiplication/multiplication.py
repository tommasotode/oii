#!/usr/bin/env python3
import sys
sys.stdin = open('input.txt')

N = int(input().strip())
K = []
for i in range(N):
    K.append(int(input().strip()))

for n in K:
    v = {'0':False,
        '1':False,
        '2':False,
        '3':False,
        '4':False,
        '5':False,
        '6':False,
        '7':False,
        '8':False,
        '9':False}

    m = 0
    while False in v.values():
        m += 1
        num = n * m
        for i in str(num):
            if v[i] == False:
                v[i] = True

    print(m)