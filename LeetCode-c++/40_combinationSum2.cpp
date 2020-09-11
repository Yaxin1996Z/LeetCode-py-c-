#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, candidates, target, path);
        return result;
    }
    
    void backtrack(int start, int sum,vector<int>&candidates, int target, vector<int>& path)
    {
        for(int i=start; i<candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            if(sum>target)
            {
                path.pop_back();
                sum -= candidates[i];
                return;
            }
            if(sum==target)
            {    
                vector<vector<int>>::iterator it;
                it = find(result.begin(),result.end(), path);
                if (it==result.end())
                {
                    result.push_back(path);
                }

            }
            backtrack(i+1, sum, candidates, target, path);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> candidates = vector<int>{10,1,2,7,6,1,5};
    vector<vector<int>> res = solution.combinationSum2(candidates, 8); 
    for(vector<int>x:res)
    {
        cout << '[';
        for(int i:x)
        {
            cout << i << ' ';
        }
        cout << ']' << endl;
    }
    system("pause");
    return 0;
}
