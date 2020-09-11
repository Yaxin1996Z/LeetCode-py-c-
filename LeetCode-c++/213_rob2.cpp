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
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n, 0); // 偷第一间房子，最后一间不能偷
        vector<int> dp2(n, 0); // 不偷第一间房子，最后一间可以偷
        dp1[1] = nums[0];
        for(int i=2; i<n; ++i)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }
        dp2[1] = nums[1];
        for(int j=2; j<n; ++j)
        {
            dp2[j] = max(dp2[j-1], dp2[j-2]+nums[j]);
        }
        return max(dp1[n-1], dp2[n-1]);
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
        if(n == 2) return max(nums[0], nums[1]);
        // 偷第一间房子，最后一间不能偷
        int pre1 = 0;
        int cur1 = nums[0];
        for(int i=2; i<n; ++i)
        {
            int tempcur = cur1;
            cur1 = max(cur1, pre1+nums[i-1]);
            pre1 = tempcur;
        }
        // 不偷第一间房子，最后一间可以偷
        int pre2 = 0;
        int cur2 = nums[1];
        for(int i=2; i<n; ++i)
        {
            int tempcur = cur2;
            cur2 = max(cur2, pre2+nums[i]);
            pre2 = tempcur;
        }
        return max(cur1, cur2);
    }
};

int main()
{
    vector<int> nums = {1,2,3,1};
    Solution solution = Solution();
    cout << solution.rob(nums) <<endl; //输出应为4
    system("pause");
    return 0;
}