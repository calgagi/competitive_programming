from collections import defaultdict
import sys

class Graph():
    def __init__(self):
        self.v = defaultdict(int)
        self.e = defaultdict(list)
    def add_connect(self, t, f, v):
        self.e[t].append([f, v])
    def add_node(self, t, v):
        self.v[t] = v

# Setup
data = sys.stdin.readlines()
num_v = int(data.pop(0).rstrip("\n"))
g = Graph()
for i in range(num_v):
    temp = data.pop(0).rstrip("\n").split(" ")
    g.add_node(temp[0], int(temp[1]))
num_e = int(data.pop(0).rstrip("\n"))
for i in range(num_e):
    temp = data.pop(0).rstrip("\n").split(" ")
    g.add_connect(temp[0], temp[1], int(temp[2]))
path = data.pop(0).rstrip("\n").split(" ")

# Use backtracking
def backtrack(distance, curr, sptset):
    if curr == path[1]:
        r.append(distance)
        return
    for v in g.e[curr]:
        if v[0] not in sptset:
            # travel to node
            sptset.append(v[0])
            distance += v[1] + g.v[v[0]]
            backtrack(distance, v[0], sptset)
            distance -= (v[1] + g.v[v[0]]) 
            sptset.pop()

sptset = []
# set source
sptset.append(path[0])
curr = path[0]
r = []

backtrack(0, curr, sptset)

print(min(r))
            
    
    




    
        
    
