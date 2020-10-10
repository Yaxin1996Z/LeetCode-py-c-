#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    void sortColor2(vector<int> & nums)
    {
        unordered_map<int, int> count;
        for(int x : nums)
        {
            count[x] ++;
        }
        for(int i=0; i<count[0]; ++i)
        {
            nums[i] = 0;
        }
        for(int i=count[0]; i<count[0]+count[1]; ++i)
        {
            nums[i] = 1;
        }
        for(int i=count[0]+count[1]; i<count[0]+count[1]+count[2]; ++i)
        {
            nums[i] = 2;
        }
    }
    void sortColor(vector<int> & nums)
    {
        int p = 0;
        int q = nums.size()-1;
        for(int i=0; i<=q; ++i)
        {
            if(nums[i]==0)
            {
                nums[i] = nums[p];
                nums[p] = 0;
                ++p;
            }
            if(nums[i]==2)
            {
                nums[i] = nums[q];
                nums[q] = 2;
                --q;
                if(nums[i]!=1)
                    --i;
            }
        }
    }
};

int main()
{
    vector<int> nums = {1,2,0};
    Solution solution = Solution();
    solution.sortColor(nums);
    cout << '[';
    for(int x: nums)
    {
        cout << x << ' ';
    }
    cout << ']' << endl;
    system("pause");
    return 0;
}