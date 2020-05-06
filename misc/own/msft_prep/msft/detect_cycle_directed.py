from collections import defaultdict

class Graph:

    def __init__(self,vertices):
        self.V= vertices
        self.graph = defaultdict(list)


    def addEdge(self,v,w):
        self.graph[v].append(w)

    def isCyclicHelper(self, v, visited, recStack):
        # Set recStack to True for this node and visited to True
        visited[v] = True
        recStack[v] = True
        # For all the connections from this node in graph
        for neighbor in self.graph[v]:
            # If it hasn't been visited yet (checked before by this func)
            if visited[neighbor] == False:
                # Check it with isCyclicHelper (this func)
                if self.isCyclicHelper(neighbor, visited, recStack) == True:
                    return True
            # If it has been checked before, and it's in the path (recStack)
            elif recStack[neighbor] == True:
                return True
        recStack[v] = False
        return False


    def isCyclic(self):
        # Setup recStack and visited
        recStack = [False] * self.V
        visited = [False] * self.V
        # For all the nodes
        for i in range(self.V):
            # If visited is false, do isCyclicHelper and pass in node, visited, recStack
            if visited[i] == False and self.isCyclicHelper(i, visited, recStack) == True:
                return True
        return False

    def removeCycles(self):
        # Setup recStack and visited
        recStack = [False] * self.V
        # For all the nodes
        for i in range(self.V):
            # If visited is false, do isCyclicHelper and pass in node, visited, recStack
            if self.removeCyclesHelper(i, recStack) == True:
                return True
        return False

    def removeCyclesHelper(self, v, recStack):
        # Set recStack to True for this node and visited to True
        recStack[v] = True
        # For all the connections from this node in graph
        for neighbor in self.graph[v]:
            print(str(v) + " " + str(neighbor))
            # If it has been checked before, and it's in the path (recStack)
            if recStack[neighbor] == True or v == neighbor:
                self.graph[v].remove(neighbor)
            else:
                self.removeCyclesHelper(neighbor, recStack)

        recStack[v] = False

# Create new graph
g = Graph(4)
# Add edges
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)
if g.isCyclic() == 1:
    print "Graph has a cycle"
else:
    print "Graph has no cycle"
print(g.graph)
g.removeCycles()
print(g.graph)
if g.isCyclic() == 1:
    print "Graph has a cycle"
else:
    print "Graph has no cycle"
