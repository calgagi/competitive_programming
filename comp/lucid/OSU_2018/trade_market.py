import sys

data = [int(d) for d in sys.stdin.readline().rstrip("\n").split(" ")]

maidx = 1
miidx = 0
val = data[maidx]-data[miidx]

for i in range(len(data)):
    if data[i] <= data[miidx]:
        miidx = i
        maidx = i+1
        if i+1 < len(data):
            val = max(data[maidx]-data[miidx], val)
    elif data[i] > data[maidx]:
        maidx = i
        val = max(data[maidx]-data[miidx], val)

print(val)
