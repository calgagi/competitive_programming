# ============= MERGE SORT ================
def merge( actObj, i, m, j ):
    # Get each half
    n1 = m - i + 1
    n2 = j - m

    # Create new temporary arrays
    L = [0]*n1
    R = [0]*n2
    for it in range(n1):
        L[it] = actObj[i + it]
    for it in range(n2):
        R[it] = actObj[m + 1 + it]

    # Start merging!
    itL = 0
    itR = 0
    it = i

    while itL < n1 and itR < n2:
        if L[itL]["start"] >= R[itR]["start"]:
            actObj[it] = L[itL]
            itL += 1
        else:
            actObj[it] = R[itR]
            itR += 1
        it += 1

    while itL < n1:
        actObj[it] = L[itL]
        itL += 1
        it += 1

    while itR < n2:
        actObj[it] = R[itR]
        itR += 1
        it += 1


def merge_sort( actObj, i, j ):
    if i < j:
        m = (i + (j-1)) / 2
        merge_sort(actObj, i, m)
        merge_sort(actObj, m+1, j)
        merge(actObj, i, m, j)
# ============= END MERGE SORT ==============
