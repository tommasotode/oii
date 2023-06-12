#!/usr/bin/env python3
# -*- coding: utf8 -*-

import sys
from collections import defaultdict
from collections import deque

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

	def BFS(self, start, Z):
		
		queue = []
		dist = []
		visited = []
		for i in self.graph.keys():
			dist.append(float('inf'))
		
		queue.append(start)
		distance = 0
		dist[0] = 0
		visited[0] = True

		while queue:
			start = queue.pop(0)
			distance += 1
			#rembember to not take everything, only the numbers in Z, else they are too big
			for i in self.graph[start]:
				if dist[i] == float('inf'):
					dist[i] = distance
					queue.append(i)

		return dist
	

	def bfs_distance(self, start, Z):

		visited = set()
		queue = deque([(start, 0)])

		while queue:
			current, distance = queue.popleft()

			if current in Z:
				return distance

			if current not in visited:
				visited.add(current)
				neighbors = self.graph[current]

				for neighbor in neighbors:
					if neighbor not in visited:
						queue.append((neighbor, distance + 1))

		return -1

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
	
	tmp = []
	for i in lampade.graph.keys():
		tmp.append(lampade.bfs_distance(i, Z))

	idx = 0
	num = max(tmp)

	return (idx, num)

T = int(input())
for t in range(1, T+1):
	print("\nCase #{}: {} {}".format(t, *solve()))