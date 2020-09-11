#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path;
        backtrack(1, 0, k, n, path);
        return result;
    }
    void backtrack(int start, int sum, int k, int n, vector<int>& path)
    {
        for(int i=start; i<10; ++i)
        {
            path.push_back(i);
            sum += i;
            if(path.size()>k)
            {
                path.pop_back();
                sum -= i;
                return;
            }
            if(sum>=n){
                if(sum==n && path.size()==k)
                    result.push_back(path);
                path.pop_back();
                sum -= i;
                return;
            }
            backtrack(i+1, sum, k, n, path);
            path.pop_back();
            sum -= i;
        }
    }
};

int main()
{
    int k = 3;
    int n = 7;
    Solution solution = Solution();
    vector<vector<int>> res = solution.combinationSum3(k, n);
    for(vector<int> x: res)
    {
        cout << '[';
        for(int i: x)
        {
            cout << i << ' ';
        }
        cout << ']' <<endl;
    }
    system("pause");
    return 0;
}