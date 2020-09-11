using namespace std;
#include<string>
#include<algorithm>
#include<iostream>

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int sum = 0;
        string res = "";
        while(i>=0 || j>=0)
        {
            if (i >= 0) sum += num1[i--]-'0'; 
            if (j >= 0) sum += num2[j--]-'0';
            res.push_back(sum % 10 + '0');
            sum /= 10;
        }
        if(sum==1)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution solution = Solution();
    string num1, num2;
    cin >> num1 >> num2;

    cout << solution.addStrings(num1, num2);
    
    system("pause");
    return 0;
}