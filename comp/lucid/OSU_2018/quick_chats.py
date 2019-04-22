import sys
from collections import defaultdict

class Graph:
    def __init__(self, x):
        self.nodes = []
        self.graph = defaultdict(list)

    def addEdge(self, x, y, w):
        temp = {
            "node": x,
            "weight": w
        }
        self.graph[y].append(temp)
        temp["node"] = y
        self.graph[x].append(temp)

    def addNode(self, name, weight):
        temp = {
            "name": name,
            "weight": weight
        }
        self.nodes.append(temp)
        
