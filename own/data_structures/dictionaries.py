dict = {"1": True, "2": False}
print(dict)

# Get keys
print(dict.keys())
dict2 = {"1": [1, 2, 3], "headers": ["Filetype", "HTML", "text/javascript"], "body": "hi i'm aiden", "true": True}
print(dict2["1"])

for v, k in dict2.items():
    print(v, k)

i, j, k = 1, 2, 3

print(i, j, k)

i = list(dict2)
print(i)
