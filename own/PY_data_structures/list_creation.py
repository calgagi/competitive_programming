squares = [x**2 for x in range(10)]
print(squares)

zero_matrix = [[0 for x in range(10)] for y in range(10)]
print(zero_matrix)

init_array = [0]*10
print(init_array)

coords = [(x,y) for x in [1, 2, 3] for y in [1, 2, 3]]
print(coords)

squares.sort()
print(squares)

for i, k in enumerate(coords):
    print(i, k)

for f in sorted(set(coords)):
    print(f)

print(coords[:-5])
