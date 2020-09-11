#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    void backtrack(vector<bool>& used, vector<int>& nums, vector<int>& path)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = 0; i<nums.size(); ++i)
        {
            if(!used[i])
            {    
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(used, nums, path);
                path.pop_back();
                used[i] =false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> used = vector<bool>(nums.size(), false);
        vector<int> path;
        backtrack(used,  nums, path);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution();
    vector<vector<int>> res = solution.permute(nums);
    for(vector<int> x: res)
    {
        cout << '[';
        for(int i: x)
        {
            cout << i << ' ';
        }
        cout << ']' << endl;
    }
    system("pause");
    return 0;
}