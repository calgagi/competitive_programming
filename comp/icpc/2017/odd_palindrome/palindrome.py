import sys

data = sys.stdin.readline()

# Find palindromic substrings in string
# Use stack in
# test to see if they're odd
isodd = True
print(len(data))
j = 0;
while j < len(data):
    i = j;
    stack = [];
    while i < len(data):
        if len(stack) != 0 and data[i] == stack[len(stack) - 1]:
            stack.pop()
            if len(stack) == 0:
                print("Or not.")
                isodd = False
                break
        else:
            stack.append(data[i])
        i = i + 1
    if isodd is False:
        break
    j = j + 1

if isodd is True:
    print("Is odd.")
