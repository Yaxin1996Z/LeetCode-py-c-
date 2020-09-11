from _collections import deque
from _collections import defaultdict

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
    def rob(self, root: TreeNode) -> int:
        """
        :param root:
        :return:
        """
        dp = defaultdict(int)
        def dfs(node):
            if node == None:
                dp[node] = 0
                return
            dfs(node.left)
            dfs(node.right)
            if node.left == None and node.right == None:
                dp[node] = node.val
                return
            if node.left == None:
                dp[node] = max(node.val + dp[node.right.left] + dp[node.right.right], dp[node.right])
                return
            if node.right == None:
                dp[node] = max(node.val + dp[node.left.left] + dp[node.left.right], dp[node.left])
                return
            else:
                dp[node] = max(
                    node.val + dp[node.right.left] + dp[node.right.right] + dp[node.left.left] + dp[node.left.right],
                    dp[node.right] + dp[node.left])
        dfs(root)
        return dp[root]

if __name__ == '__main__':
    # tree = "[3, 2, 3, null, 3, null, 1, null, null, null, 5]"
    tree = "[1, 2, 3]"
    nodeList = tree[1:-1].split(', ')
    root = creatTree(nodeList)
    solution = Solution()
    print(solution.rob(root))
