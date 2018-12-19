class TreeNode:
    val = 0
    TreeNode left = None
    TreeNode right = None

def inOrder(root, test):
    if root == None:
        return
    inOrder(root.left, test)
    test.append(root.val)
    inOrder(root.right, test)

def a
