#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        if (nums.empty()) return {{}};
        int n = nums.back();
        nums.pop_back();
        vector<vector<int>> res = subsets(nums);

        int size = res.size();
        for(int i=0; i<size; ++i)
        {
            res.push_back(res[i]);
            res.back().push_back(n);
        }
        return res;
    }

    vector<vector<int>> result;
    vector<vector<int>> subsets2(vector<int>& nums)
    {
        
        vector<int> path;
        backtrack(nums, 0, path);
        return result;
    }

    void backtrack(vector<int>&nums, int start, vector<int>& path)
    {
        result.push_back(path);
        for(int i=start; i<nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtrack(nums, i+1, path);
            path.pop_back();
        }
        
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution();
    vector<vector<int>> res = solution.subsets2(nums);
    for(vector<int> x: res)
    {
        cout << '[';
        for(int i: x){
            cout << i ;
        }
        cout << ']' <<endl;
    }
    system("pause");
    return 0;
}