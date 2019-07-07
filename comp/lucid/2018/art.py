import sys

# Setup data
data = sys.stdin.readlines()
sentence = data.pop(0).rstrip("\n")
num_char = int(data.pop(0).rstrip("\n"))
height = int(data.pop(0).rstrip("\n"))
# Parse data
table = {}
for k in range(num_char):
    # Get key
    key = data.pop(0).rstrip("\n")
    val = []
    for i in range(height):
        val.append(data.pop(0).rstrip("\n"))
    table[key] = val

# Print data
for h in range(height):
    for i in range(len(sentence)):
        sys.stdout.write(table[sentence[i]][h])
    sys.stdout.write("\n")

    

