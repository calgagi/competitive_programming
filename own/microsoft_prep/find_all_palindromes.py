from collections import defaultdict

palindromes = defaultdict(int)

string = "abaaba"

def findPalindromes(spot1, spot2):
    i = 0
    pstr = ""
    while spot1 - i >= 0 and spot2 + i < len(string):
        if string[spot1-i] == string[spot2+i] and spot1-i != spot2+i:
            pstr = string[spot1-i] + pstr + string[spot2+i]
            palindromes[pstr] = 1
            i += 1
        elif string[spot1-i] == string[spot2+i] and spot1-i == spot2+i:
            pstr = string[spot1-i]
            i += 1
        else:
            break

for spot, char in enumerate(string):
    # Odd palindromes
    findPalindromes(spot, spot)
    # Even palindromes that start on left
    findPalindromes(spot-1, spot)
    # Even palindromes that start on right
    findPalindromes(spot, spot+1)

print(palindromes)
