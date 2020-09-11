from _collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BTree:
    def creatTree(self, nodeList):
        if nodeList[0] == "null":
            return None
        root = TreeNode(int(nodeList[0]))
        i = 1
        Nodes = [root]
        for node in Nodes:
            if node != None:
                node.left = TreeNode(int(nodeList[i])) if nodeList[i] != "null" else None
                Nodes.append(node.left)
                i += 1
                if i == len(nodeList): return root
                node.right = TreeNode(int(nodeList[i])) if nodeList[i] != "null" else None
                Nodes.append((node.right))
                i += 1
                if i == len(nodeList):
                    return root

    def DFStraverse(self, root: TreeNode):
        """
        深度优先遍历
        """
        if root == None:
            print("null")
            return
        else:
            print(root.val)
        self.traverse(root.left)
        self.traverse(root.right)

    def BFStraverse(self, root):
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            if not node:
                print("null")
                continue
            print(node.val)
            q.append(node.left)
            q.append(node.right)


class Solution:
    def recoverTree(root: TreeNode) -> TreeNode:
        return root


if __name__ == '__main__':
    str = "[1, 3, null, null, 2]"
    tree = BTree()
    root = tree.creatTree(str[1:-1].split(', '))
    tree.BFStraverse(root)
    # solution = Solution()
    # solution.recoverTree(root)
    # solution.traverse()
