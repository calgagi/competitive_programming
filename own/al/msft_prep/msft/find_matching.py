data = [1, 2, 30, 3, 4, 5, 6, 8, 9, 20, 30]

toMatch = 50

seen = {}

for i in data:
    if i not in seen:
        seen[i] = True
    if toMatch - i in seen:
        print("Match: " + str(i) + " " + str(toMatch - i))
        break
