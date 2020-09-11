#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> path;
        backtrack(n, k, 1, path);
        return result;
    }

    void backtrack(int n, int k, int start, vector<int>&path)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        
        for(int i=start; i<n+1; ++i)
        {
            path.push_back(i);
            backtrack(n, k, i+1, path);
            path.pop_back();
        }
    }
};

int main()
{
    Solution solution = Solution();
    int n = 4;
    int k = 2;
    vector<vector<int>> res = solution.combine(n, k);
    for(vector<int> x: res){
        cout << '[' ;
        for(int i: x){
            cout << i ;
        }
        cout << ']' <<endl;
    }
    system("pause");
    return 0;
}