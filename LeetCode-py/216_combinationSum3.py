class Solution:
    @classmethod
    def combinationSum3(self, k, n):
        result = []
        def backtrack(start, sum, path):
            for i in range(start, 10):
                sum += i
                if(len(path)>=k):
                    return
                if(sum==n and len(path)==k-1):
                    result.append(path+[i])
                    sum -= i
                    return
                if(sum>n):
                    sum -= i
                    return
                backtrack(i+1, sum, path+[i])
                sum -= i

        backtrack(1, 0, [])
        return result
if __name__ == "__main__":
    k = 3
    n = 9
    print(Solution.combinationSum3(k, n))