#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrack(used, nums, path);
        return result;
    }
    void backtrack(vector<bool> used, vector<int> nums, vector<int> path)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = 0; i<nums.size(); ++i)
        {
            if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1]))
            {
                continue;
            }
            else
            {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(used, nums, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};


int main()
{
    Solution solution = Solution();
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = (solution.permuteUnique(nums));
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