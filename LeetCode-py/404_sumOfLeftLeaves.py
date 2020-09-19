class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def createTree(self, nodeList):
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

    def preorderTraversal(self, root: TreeNode):
        if root!=None:
            print(root.val, end=' ')
            self.preorderTraversal(root.left)
            self.preorderTraversal(root.right) 

class Solution:
    @classmethod
    def sumOfLeftLeaves(self, root: TreeNode):
        self.summ = 0
        def dfs(root, left):
            if not root:
                return
            if(not root.left and not root.right and left):
                self.summ += root.val
            dfs(root.left, True)
            dfs(root.right, False)
        dfs(root, False)
        return self.summ


if __name__ == "__main__":
    t = Tree()
    t.root = t.createTree([3,9,20,None,None,15,7])
    print("先序遍历：")
    t.preorderTraversal(t.root)
    print("\n左叶子之和：", Solution.sumOfLeftLeaves(t.root))
    
