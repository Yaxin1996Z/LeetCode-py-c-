class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i = len(num1) - 1
        j = len(num2) - 1
        digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

        temps = 0
        res = ""
        while i >= 0 or j >= 0:
            temps += digits[num1[i]] if i >= 0 else 0
            temps += digits[num2[j]] if j >= 0 else 0
            res = list(digits.keys())[list(digits.values()).index(temps % 10)] + res
            temps = temps // 10
            i -= 1
            j -= 1
        return '1' + res if temps == 1 else res


if __name__ == '__main__':
    solution = Solution()
    num1, num2 = input().split()
    print(solution.addStrings(num1, num2))
