import sys

data = sys.stdin.readlines()

num_cards = int(data[0].rstrip("\n").split(" ")[0])
tc = int(data[0].rstrip("\n").split(" ")[1])
total = 0
for j in range(1, num_cards+1):
    total += j


for i in range(1, tc+1):
    cards = [int(d) for d in data[i].rstrip("\n").split(" ")]
    temp = total
    for j in cards:
        temp -= j
    print(temp)
        
