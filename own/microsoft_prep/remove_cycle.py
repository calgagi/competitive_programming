from collections import defaultdict

class Graph:
    def __init__(self, V):
        self.V = V
        self.edges = defaultdict(list)

    def add_edge(self, a, b):
        if a < self.V and b < self.V:
            self.edges[a].append(b)
        else:
            print("Not a valid edge creation")

    def remove_cycles_Help(self, vect, recStack):
        recStack[vect] = True
        for neighbor in self.edges[vect]:
            if recStack[neighbor] == True:
                self.edges[vect].remove(neighbor)
            else:
                self.remove_cycles_Help(neighbor, recStack)
        recStack[vect] = False

    def remove_cycles(self):
        recStack = [False]*self.V
        for vect in range(self.V):
            self.remove_cycles_Help(vect, recStack)


g = Graph(5)

g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 4)
g.add_edge(4, 1)

print(g.edges)

g.remove_cycles()

print(g.edges)
