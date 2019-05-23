import sys

data = sys.stdin.readlines()
bs = [int(x) for x in data[0].rstrip("\n").split(" ")]

mini = bs[0]
ans = -10000001
for i in range(1, len(bs)):
    mini = min(bs[i-1], mini)
    ans = max(ans, bs[i]-mini)

print(ans)
