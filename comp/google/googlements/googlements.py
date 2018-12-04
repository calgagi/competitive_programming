import sys

data = True

while data:
    data = sys.stdin.readline() # read line from stdin
    data = data.rstrip('\n')  # get rid of newline character
    print(data)
