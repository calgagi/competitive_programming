import sys

moves = sys.stdin.readline().rstrip("\n")

pos = [0,0]
facing = 0

for m in moves:
    if m == "F":
        if facing == 0:
            pos[0] += 1
        elif facing == 1:
            pos[1] += 1
        elif facing == 2:
            pos[0] -= 1
        elif facing == 3:
            pos[1] -= 1
    elif m == "R":
        facing = (facing + 1) % 4
    elif m == "L":
        facing -= 1
        if facing == -1:
            facing = 3

if pos[0] == 0 and pos[1] == 0:
    print(1)
elif facing == 2:
    print(2)
elif facing == 1 or facing == 3:
    print(4)
else:
    print(-1)
    
