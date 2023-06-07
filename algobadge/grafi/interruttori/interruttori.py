#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys
from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def printGraph(self):
		for pos in self.graph.keys():
			print(str(pos) + " -> ", end="")
			for i in self.graph[pos]:
				print(str(i) + " -> " , end="")

			print("\n")

	def BFS(self, start, dest):
		if start == dest:
			return 1
		
		visited = [False] * (max(self.graph) + 1)
		visited[start] = True
		queue = []
		queue.append(start)

		dist = 0
		while queue:
			start = queue.pop(0)
			dist += 1
			for i in self.graph[start]:
				if visited[i] == False:
					queue.append(i)
					visited[i] = True
				if i == dest:
					return dist + 1


sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

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
	
	lampade = Graph()
	for i, j in zip(X, Y):
		lampade.addEdge(i, j)
	
	a = []
	for i in lampade.graph.keys():
		b = []
		for j in Z:
			b.append(lampade.BFS(i, j))
		a.append(min(b))

	idx = list(lampade.graph.keys()).index(max(a))
	num = max(a)

	return (idx, num)

T = int(input())
for t in range(1, T+1):
	print("\nCase #{}: {} {}".format(t, *solve()))