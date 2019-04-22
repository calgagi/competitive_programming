import sys

data = sys.stdin.readline().rstrip("\n")
shift = 3
rstring = ""
loweralphabet = "abcdefghijklmnopqrstuvwxyz"
upperalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for c in data:
    if c.isalpha():
        if c in loweralphabet:
            rstring += loweralphabet[(loweralphabet.index(c) + shift) % 26]
        elif c in upperalphabet:
            rstring += upperalphabet[(upperalphabet.index(c) + shift) % 26]
        shift += 1
    else:
        rstring += c
        
print(rstring)
