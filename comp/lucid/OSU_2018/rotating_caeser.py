import sys

data = sys.stdin.readline().replace("\n", " ")
counter = 3
result = ""

for i,c in enumerate(data):
    if c <= 'Z' and c >= 'A':
        result += chr((ord(c)-65+counter)%26 + 65)
        counter += 1
    elif c <= 'z' and c >= 'a':
        result += chr((ord(c)-97+counter)%26 + 97)
        counter += 1
    else:
        result += c
    counter = counter % 26

print(result)
