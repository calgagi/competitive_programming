class TreeNode:
    def __init__(self, val):
        self.data = val
        self.r = None
        self.l = None

def find_Val(tree, path, val):
    if tree.data == val:
        return True
    if tree.r != None:
        if find_Val(tree.r, path, val):
            path.append("right")
            return True
    if tree.l != None:
        if find_Val(tree.l, path, val):
            path.append("left")
            return True
    return False


head = TreeNode(5)
head.l = TreeNode(0)
head.r = TreeNode(4)
head.l.l = TreeNode(1)
head.l.r = TreeNode(2)
head.r.l = TreeNode(3)
head.r.r = TreeNode(6)

path = []
find_Val(head, path, 1)
print(path)
