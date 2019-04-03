import sys

data = int(sys.stdin.readline().rstrip("\n"))

if data % 4 == 0 or (data % 2 == 0 and data > 4):
	print("YES")
else:
	print("NO") 
