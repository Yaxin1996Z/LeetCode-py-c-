class Solution:
    def subsets(self, nums):
        result = []
        path = []
        def backtrack(start, path):
            result.append(path)
            for i in range(start, len(nums)):
                backtrack(i+1, path+[nums[i]])
        backtrack(0, path)
        return result

if __name__ == '__main__':
    nums = [1, 2, 3]
    solution = Solution()
    print(solution.subsets(nums))
