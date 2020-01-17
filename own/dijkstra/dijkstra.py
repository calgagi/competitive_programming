class Graph:
    def __init__(self,vertices):
        self.V = vertices #No. of vertices
        self.graph = [[-1 for row in range(vertices)] for col in range(vertices)]
        self.node_vals = [0 for i in range(vertices)]

    def addEdge(self, f, t, w):
        self.graph[f][t] = w + self.node_vals[t]
        
    def addNodeVal(self, i, v):
        self.node_vals[i] = v
        
    def dijkstra(self, src, dest):
        dist = [float('inf')] * self.V
        subset = [False] * self.V
        dist[src] = 0
        curr = src
        for j in range(self.V):
            visit = self.dijkstraMinNotVisited(subset, dist)
            subset[visit] = True
            for i in range(self.V):
                if self.graph[visit][i] > -1 and subset[i] == False and dist[i] > dist[visit] + self.graph[visit][i]:
                    dist[i] = dist[visit] + self.graph[visit][i]
        return dist[dest]
        
    def dijkstraMinNotVisited(self, subset, dist):
        mi_index = 0
        mi = float('inf')
        for i in range(self.V):
            if dist[i] < mi and subset[i] == False:
                mi = dist[i]
                mi_index = i
        return mi_index
