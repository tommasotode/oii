#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys

# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

def solve():
    input()
    N, A, B = map(int, input().split())
    Z = [None] * A
    X = [None] * B
    Y = [None] * B

    for j in range(A):
        Z[j] = int(input())
    for j in range(B):
        X[j], Y[j] = map(int, input().split())
    
    idx = 42 # memorizza qui l'indice della lampadina
    num = 42 # memorizza qui il numero di interruttori
    
    # aggiungi codice...

    return (idx, num)


T = int(input())

for t in range(1, T+1):
    print("Case #{}: {} {}".format(t, *solve()))