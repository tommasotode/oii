from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, master, vertex):
		self.graph[master].append(vertex)

	def printGraph(self):
		for pos in self.graph.keys():
			print(str(pos) + " -> ", end="")
			for i in self.graph[pos]:
				print(str(i) + " -> " , end="")

			print("\n")

	def BFS(self, current):
		visited = [False] * (max(self.graph) + 1)
		visited[current] = True
		to_visit = []
		to_visit.append(current)

		# while the queue is not empty
		while to_visit:

			# pop should be for stacks, but it is sufficient to pop the first element to
			# make it a queue
			current = to_visit.pop(0)
			print(current, end=" ")

			# iterate over the linked list of connections of the current vertex
			for i in self.graph[current]:
				if visited[i] == False:
					to_visit.append(i)
					visited[i] = True


if __name__ == '__main__':
	g = Graph()
	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(1, 2)
	g.addEdge(2, 0)
	g.addEdge(2, 3)
	g.addEdge(3, 3)
	g.printGraph()
