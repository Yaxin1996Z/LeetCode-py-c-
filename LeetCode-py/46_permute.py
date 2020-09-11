class Solution:
    @classmethod
    def permute(self, nums):
        result = []
        used = [False for _ in range(len(nums))]
        def backtrack(path):
            if(len(path) == len(nums)):
                result.append(path)
                return
            for i in range(len(nums)):
                if not used[i]:
                    used[i] = True
                    backtrack(path + [nums[i]])
                    used[i] = False
        backtrack([])
        return result

if __name__ == '__main__':
    nums = [1, 2, 3]
    print(Solution.permute(nums))
