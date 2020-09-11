from _collections import deque

class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        自己写的方法
        :type numCourse: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        if len(prerequisites) == 0:
            return True

        def _next(coursei):
            for i in range(len(prerequisites)):
                if issearched[i] == 0 and coursei == prerequisites[i][0]:
                    issearched[i] = 1
                    return prerequisites[i][1]
            else:
                return -1

        issearched = [0] * len(prerequisites)
        stack = [prerequisites[0][0], prerequisites[0][1]]
        issearched[0] = 1
        while (stack or 0 in issearched):
            if not stack:
                for i in range(len(prerequisites)):
                    if issearched[i] == 0:
                        stack = [prerequisites[i][0], prerequisites[i][1]]
                        issearched[i] = 1
                        break
            node = stack[-1]
            next_node = _next(stack[-1])
            if next_node in stack:
                return False
            if next_node == -1:
                stack.pop()
            else:
                stack.append(next_node)
        else:
            return True

class Solution2:
    def canFinish(self, numCourses, prerequisites):
        """
        入度表(BFS)
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        indegree = [0] * numCourses
        adjacency = [[] for _ in range(numCourses)]
        q = deque()
        for cur, pre in prerequisites:
            indegree[cur] += 1
            adjacency[pre].append(cur)
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        while q:
            pre = q.popleft()
            numCourses -= 1
            for cur in adjacency[pre]:
                indegree[cur] -= 1
                if indegree[cur] == 0:
                    q.append(cur)
        return not numCourses

class Solution3():
    def canFinish(self, numCourses, prerequisites):
        def dfs(i):
            if visited[i] == -1:
                return True
            if visited[i] == 1:
                return False
            visited[i] = 1
            for v in adjacency[i]:
                    return False
            visited[i] = -1
            return True

        adjacency = [[] for _ in range(numCourses)]
        visited = [0] * numCourses

        for cur, pre in prerequisites:
            adjacency[pre].append(cur)

        for i in range(numCourses):
            if not dfs(i):
                return False
        else:
            return True


if __name__ == '__main__':
    numCourse = 3
    prerequisites = [[1, 0], [0, 2], [2, 0]]
    solution = Solution3()
    print(solution.canFinish(numCourse, prerequisites))
