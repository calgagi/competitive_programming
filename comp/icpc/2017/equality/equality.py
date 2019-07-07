import sys


while 1 < 2:
    data = sys.stdin.readline()
    print(data)
    if data == "":
        break

    firstnum = int(data[0])
    secondnum = int(data[4])

    answer = firstnum + secondnum;
    if answer == int(data[8]):
        print("YES")
    else:
        print("NO")
