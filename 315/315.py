# Online Judge : UVA Online Judge
# Problem No   : 315
# Problem Name : Network
# Author       : Zubayer Rahman
# Email        : zubayer.csesust@gmail.com
# Time Limit   : 3.000s
# CPU          : 0.070s
# Memory       :
# Algorithm    : Articulation Point/Bridge


import sys
from collections import defaultdict


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

    def DFS(self, root: int):
        self.time += 1

        self.visited[root] = True
        self.discover_time[root] = self.time
        self.lower[root] = self.discover_time[root]

        child: int = 0

        while self.graph[root]:
            v: int = self.graph[root].pop(0)

            if not self.visited[v]:
                child += 1
                self.parent[v] = root

                self.DFS(v)

                self.lower[root] = min(self.lower[root], self.lower[v])

                if self.discover_time[root] <= self.lower[v] and not self.parent[root] == -1:
                    self.articulation_points.add(root)

                if child > 1 and self.parent[root] == -1:
                    self.articulation_points.add(root)
            elif self.parent[root] != v:
                self.lower[root] = min(self.lower[root], self.discover_time[v])


def main():
    try:
        sys.stdin = open("input.txt", "r")
    except:
        pass

    while True:
        n = int(sys.stdin.readline().strip())
        if n == 0:
            break

        graph = Graph()

        while True:
            s = sys.stdin.readline().strip()
            if s == "0":
                break

            nodes = list(map(lambda x: int(x), s.split()))

            u = nodes[0]
            for v in nodes[1:]:
                graph.addEdge(u, v)
                graph.addEdge(v, u)

        graph.DFS(1)

        sys.stdout.write("{}\n".format(len(graph.articulation_points)))


if __name__ == '__main__':
    main()
