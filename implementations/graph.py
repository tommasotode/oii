from collections import defaultdict

class Graph:
	def __init__(self, N):
		self.graph = defaultdict(list)
		self.N = N

	def addEdge(self, u, v):
		self.graph[u].append(v)
		self.graph[v].append(u)