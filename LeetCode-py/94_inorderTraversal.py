class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def createTree(nodeList):
    if (not nodeList[0]):
        return None
    root = TreeNode(nodeList[0])
    i = 1
    Nodes = [root]
    for node in Nodes:
        if node != None:
            node.left = TreeNode(nodeList[i]) if nodeList[i] != None else None
            Nodes.append(node.left)
            i += 1
            if i == len(nodeList): return root
            node.right = TreeNode(nodeList[i]) if nodeList[i] != None else None
            Nodes.append((node.right))
            i += 1
            if i == len(nodeList): return root

class Solution:
    @classmethod
    def inorderTraversal(self, root: TreeNode):
        def dfs(root):
            if root!=None:
                dfs(root.left)
                res.append(root.val)
                dfs(root.right) 
        res = []
        dfs(root)
        return res

if __name__ == "__main__":
    treelist = [1, None, 2, 3]
    root = createTree(treelist)
    print(Solution.inorderTraversal(root))
