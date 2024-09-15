#!/usr/bin/env python3

import sys

sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

p = {1:25, 2:18, 3:15, 4:12, 5:10, 6:8, 7:6, 8:4, 9:2, 10:1}

T = int(input().strip())
for test in range(1, T+1):
    input()
    N = int(input().strip())
    P = list(map(int, input().strip().split()))  


    wins, losses, score = 0, 0, 0
    
    for i in P:
        score += p.get(i, 0)
        if i == 1:
            wins += 1
        else:
            losses += 1

    if wins*18 + losses*25 > score:
        print('Practice harder')
    else:
        print('Champion')

sys.stdout.close()