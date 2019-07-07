import sys

moves = sys.stdin.readline().rstrip("\n")

direction = 0
location = [0]*2

for move in moves:
    if move == "R":
        direction = (direction+1)%4
    elif move == "L":
        direction -= 1
        if direction == -1:
            direction = 3
    if move == "F":
        if direction == 0:
            location[0] += 1
        elif direction == 1:
            location[1] += 1
        elif direction == 2:
            location[0] -= 1
        elif direction == 3:
            location[1] -= 1

if location[0] == 0 and location[1] == 0:
    print("1")
elif direction == 0:
    print("-1")
elif direction == 1 or direction == 3:
    print("4")
elif direction == 2:
    print("2")
