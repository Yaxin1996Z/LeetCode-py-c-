class Solution:
    @classmethod
    def combine(cls, n, k):
        result = []
        def backtrack(start, path):
            if len(path)==k:
                result.append(path)
                return
            for i in range(start, n+1):
                backtrack(i+1, path + [i])
        backtrack(1, [])
        return result

if __name__ == '__main__':
    n = 4
    k = 2
    print(Solution.combine(n, k))
