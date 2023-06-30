#!/usr/bin/env python3

import sys

sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

def max_group(arr):
	curr = 0
	groups = []
	for i in arr:
		if i == -1:
			groups.append(curr)
			curr = 0
		else:
			curr = curr + i + 1

	groups.append(curr)
	
	return max(groups) - 1

def max_line(arr):
	curr = 0
	groups = []
	for i, elem in enumerate(arr):
		if elem == -1:
			curr = curr + arr[i+1]
			groups.append(curr)
			curr = 0
		else:
			curr = curr + elem + 1
	
	return min(groups) - 1
	
def solve(t):
	input()
	N = int(input().strip())
	W = list(map(int, input().strip().split()))	

	K1 = max_group(W)
	K2 = max_line(W)

	print(f"Case #{t}: {K1} {K2}")

T = int(input().strip())

for t in range(1, T + 1):
	solve(t)