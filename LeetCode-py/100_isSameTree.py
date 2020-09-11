from _collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def creatTree(nodeList):
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
            if i == len(nodeList): return root

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        """
        自己的方法，BFS，但是内存和时间消耗比较大
        :param p:第一个树的根节点
        :param q:第二个树的根节点
        :return:两棵树是否一致
        """
        def isdiff(a: TreeNode, b: TreeNode):
            if not a and not b:
                return False
            if not a or not b or a.val != b.val:
                return True
            queue1.append(a)
            queue2.append(b)
        queue1 = deque()
        queue2 = deque()
        if isdiff(p, q):
            return False
        while(queue1):
            node1 = queue1.popleft()
            node2 = queue2.popleft()
            if isdiff(node1.left, node2.left):
                return False
            if isdiff(node1.right, node2.right):
                return False
        else:
            return True


class Solution2:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        """
        深度优先搜索
        """
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

if __name__ == '__main__':
    # tree = "[3, 2, 3, null, 3, null, 1, null, null, null, 5]"
    tree1 = "[1, null, 1, 1]"
    tree2 = "[1, 2, 1]"
    p = creatTree(tree1[1:-1].split(', '))
    q = creatTree(tree2[1:-1].split(', '))
    solution = Solution2()
    print(solution.isSameTree(p, q))
