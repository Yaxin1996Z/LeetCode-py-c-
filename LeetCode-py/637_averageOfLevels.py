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

class Solution:
    @classmethod
    def averageOfLevels(self, root):
        def dfs(root, level):
            if not root:
                return
            if(level<len(count)):
                sums[level] += root.val
                count[level] += 1
            else:
                sums.append(root.val)
                count.append(1)
            dfs(root.left, level+1)
            dfs(root.right, level+1)
        count = []
        sums = []
        dfs(root, 0)
        return [s/c for s, c in zip(sums, count)]

if __name__ == "__main__":
    treelist = [3,9,20,None,None,15,7]
    root = creatTree(treelist)
    print(Solution.averageOfLevels(root))
