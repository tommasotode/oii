#!/usr/bin/env python3

import sys

sys.stdin = open('rettangolo_input_1.txt')
sys.stdout = open('output.txt', 'w')

def count(array, element):
	res = 0
	for i in array:
		if i == element:
			res += 1

	return res

def solve(t):
	input()

	x1, y1 = map(int, input().strip().split())
	x2, y2 = map(int, input().strip().split())
	x3, y3 = map(int, input().strip().split())

	x = [x1, x2, x3]
	y = [y1, y2, y3]
	
	# conto il numero di elementi in verticale, 
	# se sono due l'unico rimasto va messo nel risultato
	x4 = 42
	y4 = 42

	for i in x:
		if count(x, i) == 1:
			x4 = i

	for i in y:
		if count(y, i) == 1:
			y4 = i

	print(f"Case #{t}: {x4} {y4}")

T = int(input().strip())

for t in range(1, T + 1):
	solve(t)

sys.stdout.close()