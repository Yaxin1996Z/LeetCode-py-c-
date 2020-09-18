
class Solution:
    def permuteUnique(self, nums):
        nums = sorted(nums)
        result = []
        length = len(nums)
        used = [False for _ in range(length)]
        def backtrack(used, path):
            if len(path)==length:
                result.append(path)
                return
            for i in range(length):
                if (used[i]) or (i>0 and nums[i]==nums[i-1] and used[i-1]==False):
                    continue
                else:
                    used[i] = True
                    backtrack(used, path + [nums[i]])
                    used[i] = False
        backtrack(used, [])
        return result

if __name__ == "__main__":
    solution = Solution()
    print(solution.permuteUnique([1,1,2]))
