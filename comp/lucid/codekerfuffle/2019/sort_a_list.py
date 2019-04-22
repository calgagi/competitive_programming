import sys

data = sys.stdin.readline().rstrip("\n").split(" ")
a = int(data[0])
c = int(data[1])
m = int(data[2])
seed = int(data[3])
count = int(data[4])

def hash(NUMS):
    hash = 1
    for num in NUMS:
        hash = (num * hash + 5147) % 40993
    return hash

NUMS = [seed]
for i in range(count):
    NUMS.append((a * NUMS[i] + c) % m)
NUMS.pop(0)
NUMS.sort()
print(NUMS)
print(hash(NUMS))
