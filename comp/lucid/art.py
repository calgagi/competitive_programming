import sys

data = sys.stdin.readlines()

# Get important stuff
output = data[0].rstrip("\n")
chars = int(data[1].rstrip("\n"))
size = int(data[2].rstrip("\n"))

# Create map and put characters into their slots
asciiMap = {}
iterator = 3
for i in range(chars):
    char = data[iterator].rstrip("\n")
    iterator += 1
    temp = []
    for j in range(size):
        temp.append(data[iterator].rstrip("\n"))
        iterator += 1
    asciiMap[char] = temp

for i in range(size):
    for j in range(len(output)):
        sys.stdout.write(asciiMap[output[j]][i])
    sys.stdout.write("\n")
