
from _collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def creatTree(nodeList):
    if nodeList[0] == None:
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

def preorderTraversal(root: TreeNode):
    def dfs(root):
        if root!=None:
            res.append(root.val)
            dfs(root.left)
            dfs(root.right) 
    res = []
    dfs(root)
    return res

class Solution:
    @classmethod
    def invertTree(self, root: TreeNode) -> TreeNode:
        if(not root): return None
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left = right
        root.right = left
        return root

if __name__ == "__main__":
    treelist = [3,9,20,None,None,15,7]
    root = creatTree(treelist)
    print(preorderTraversal(Solution.invertTree(root)))
