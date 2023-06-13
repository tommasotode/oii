#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys
from collections import defaultdict

sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

class Graph:
	def __init__(self, N):
		self.graph = defaultdict(list)
		self.N = N

	def addEdge(self, u, v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def BFS(self, start, Z):
		queue = []
		dist = [0] * self.N
		visited = [False] * self.N
		
		queue.append(start)
		dist[start] = 0
		visited[start] = True

		while queue:
			v = queue.pop(0)

			if v in Z:
				return (start, dist[v]+1)

			for i in self.graph[v]:
				if not visited[i]:
					visited[i] = True
					dist[i] = dist[v] + 1
					queue.append(i)
					
		return -1

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

	lampade = Graph(N)
	for i, j in zip(X, Y):
		lampade.addEdge(i, j)

	tmp = []
	for i in lampade.graph.keys():
		tmp.append(lampade.BFS(i, Z))
	
	maxdist = 0
	maxidx = 0
	for index, distance in tmp:
		if distance > maxdist:
			maxdist = distance
			maxidx = index

	idx = maxidx
	num = maxdist

	return (idx, num)


T = int(input())

for t in range(1, T+1):
	print("Case #{}: {} {}".format(t, *solve()))