# testcase
matrix = [['A', 'B', 'H', 'K'], ['C', 'C', 'D', 'G'], ['A', 'B', 'D', 'F']]

def dynamic_programming_func():
    mem = [[0]*(len(matrix[0])+1)]*(len(matrix)+1)
    for j in range(1, len(matrix[0])+1):
        for i in range(1, len(matrix)+1):
            max = 0
            if ord(matrix[i-1][j-1]) - ord(matrix[i-2][j-1]) == 1:
                if max < mem[i-1][j]:
                    max = mem[i-1][j]+1
            if ord(matrix[i-1][j-1]) - ord(matrix[i][j-1]) == 1:
                if max < mem[i+1][j]:
                    max = mem[i+1][j]+1
            if ord(matrix[i-1][j-1]) - ord(matrix[i-1][j]) == 1:
                if max < mem[i][j+1]:
                    max = mem[i][j+1]+1
            if ord(matrix[i][j]) - ord(matrix[i][j-1]) == 1:
                if max < mem[i][j-1]:
                    max = mem[i][j-1]+1
            mem[i][j] = max
    return mem[4][3]

print(dynamic_programming_func())
