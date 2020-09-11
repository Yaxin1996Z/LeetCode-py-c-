class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorial = [1 for _ in range(n+1)]
        for i in range(2, n+1):
            factorial[i] = factorial[i-1] * i
        a = [str(i) for i in range(1, n+1)]
        res = ''
        for i in range(n-1, -1, -1):
            j = k//(factorial[i])
            k = k-factorial[i]*j
            if k==0:
                res += a[j-1]
                a.pop(j-1)
                res += ''.join(reversed(a))
                break
            res += a[j]
            a.pop(j)
            if k==1:
                res += ''.join(a)
                break
        return res

if __name__ == "__main__":
    solution = Solution()
    n, k = map(int, input().split())
    print(solution.getPermutation(n, k))
