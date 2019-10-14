import sys
from collections import defaultdict

data = sys.stdin.readlines()
T = int(data.pop(0))
for i in range(1, T+1):
    NQ = data.pop(0).split()
    N = int(NQ[0])
    Q = int(NQ[1])
    blocks = data.pop(0)

    count = 0
    for r in range(Q):
        LR = data.pop(0).split()
        L = int(LR[0])
        R = int(LR[1])
        
        seen = defaultdict(int)
        for c in blocks[L-1:R]:
            seen[c] += 1
        seenOne = 0
        for key in seen.keys():
            if seen[key] % 2 == 1:
                seenOne += 1
                if seenOne == 2:
                    break
        if seenOne == 1 or seenOne == 0:
            count += 1
    print("Case #" + str(i) + ": " + str(count))
    
