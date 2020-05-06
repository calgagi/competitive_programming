from collections import defaultdict
import sys

class Graph():
    def __init__(self, x):
        self.V = x
        self.graph = [[-1 for column in range(x)]  
                      for row in range(x)]
        self.nv = []        
        
    def add_node(self, v):
        self.nv.append(v)
        
    def add_edge(self, t, f, v):
        self.graph[t][f] = v + self.nv[f]

    def minDistance(self, dist, sptSet): 
        mini = float('inf')
        for v in range(self.V): 
            if dist[v] < mini and sptSet[v] == False: 
                mini = dist[v] 
                min_index = v 
  
        return min_index

    def dijkstra(self, src, dest, dist): 
        dist[src] = 0
        sptSet = [False] * self.V 
  
        for cout in range(self.V): 
            u = self.minDistance(dist, sptSet) 
            sptSet[u] = True
            for v in range(self.V): 
                if self.graph[u][v] > -1 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]: 
                        dist[v] = dist[u] + self.graph[u][v] 
        
# Setup
data = sys.stdin.readlines()
num_v = int(data.pop(0).rstrip("\n"))
table = {}

g = Graph(num_v)
for i in range(num_v):
    temp = data.pop(0).rstrip("\n").split(" ")
    g.add_node(int(temp[1]))
    table[temp[0]] = i 
    
num_e = int(data.pop(0).rstrip("\n"))
for i in range(num_e):
    temp = data.pop(0).rstrip("\n").split(" ")
    g.add_edge(table[temp[0]], table[temp[1]], int(temp[2]))
    
path = data.pop(0).rstrip("\n").split(" ")
src = table[path[0]]
dest = table[path[1]]

# Dijkstra
dist = [float('inf')] * g.V 
g.dijkstra(src, dest, dist)
print(dist[dest])
    




    
        
    
