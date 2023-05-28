#!/usr/bin/env python3

import sys
import itertools
# se preferisci leggere e scrivere da file
# ti basta decommentare le seguenti due righe:

sys.stdin = open('quadrante_input_2.txt')
sys.stdout = open('output.txt', 'w')

def is_reachable(cords1, cords2):
	if cords1[0] > cords2[0] or cords1[1] > cords2[1]:
		return False
	else:
		return True

def check_max_permutation(arr):
	max = 0
	current = 0
	cords1 = (0, 0)
	perms = list(itertools.permutations(arr))
	for i, minilist in enumerate(perms):
		for j in range(len(minilist)):
			cords2 = minilist[j]
			if is_reachable(cords1, cords2):
				current += 1
			else:
				break
		if current > max:
			max = current
		current = 0

	return max - 1

def make_tuple(x, y):
	return (x, y)

def make_array(x, y):
	arr = []
	for i in range(len(x)):
		arr.append(make_tuple(x[i], y[i]))
	
	return arr


def solve(t):
	input() # prima riga vuota
	
	N = int(input().strip())
	X = []
	Y = []
	for _ in range(N):
		x, y = map(int, input().strip().split())
		X.append(x)
		Y.append(y)

	risposta = check_max_permutation(make_array(X, Y))
	print(f"Case #{t}: {risposta}")


T = int(input().strip())

for t in range(1, T + 1):
	solve(t)

sys.stdout.close()