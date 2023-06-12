from collections import deque
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

