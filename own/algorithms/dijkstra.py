# Python Program to use dijkstra's

from collections import defaultdict

#This class represents a undirected graph using adjacency list representation
class Graph:

    def __init__(self,vertices):
        self.V= vertices #No. of vertices
        self.graph = [[-1 for row in range(vertices)] for col in range(vertices)]
        self.node_vals = [0 for i in range(vertices)]
    # function to add an edge to graph

    def addEdge(self,t,f,w):
        self.graph[f][t] = w + node_vals[t]

    def dijkstra(self, src, dest):
        dist = [float('inf')] * self.V
          
    
