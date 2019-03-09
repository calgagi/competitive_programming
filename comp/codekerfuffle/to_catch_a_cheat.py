import sys

data = sys.stdin.readlines()
init = data.pop(0).rstrip("\n")
n, t = int(init.split(" ")[0]), int(init.split(" ")[1])

tc = []
for i in range(t):
    tc.append([int(x) for x in data.pop(0).split(" ")])

for i in range(len(tc)):
    s = sum(tc[i])
    x = sum(range(n+1))
    print(x-s)
    
        
