import sys
from collections import defaultdict
from sys import stdin, stdout


class Graph:
    MAX_NODES = 100

    def __init__(self):
        self.graph = defaultdict(list)

        self.visited = [False] * Graph.MAX_NODES
        self.discover_time = [0] * Graph.MAX_NODES
        self.lower = [0] * Graph.MAX_NODES
        self.parent = [-1] * Graph.MAX_NODES

        self.articulation_points = set()

        self.time = 0

    def addEdge(self, u: int, v: int):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def DFS(self):
        pass
