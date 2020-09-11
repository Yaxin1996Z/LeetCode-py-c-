using namespace std;
#include<iostream>
#include<vector>


class Solution
{
    public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n,0);
        dp[1] = nums[0];
        for(int i=2; i<n+1; ++i )
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};

class Solution2
{
    public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int cur = nums[0];
        int pre = 0;
        for(int i=2; i<n+1; ++i )
        {
            int tempcur = cur;
            cur = max(cur, pre+nums[i-1]);
            pre = tempcur;
        }
        return cur;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = {1, 2, 3, 1}; 

    cout << solution.rob(nums);
    
    system("pause");
    return 0;
}