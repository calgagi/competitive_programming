import sys

data = sys.stdin.readline().split(" ")

curr = ""
r = ""

for j in range(53, len(data)):
    curr = str(int(data[j]) % 2) + curr
    if len(curr) == 8:
        print(curr)
        r += chr(int(curr, 2))
        curr = ""
print(r)
