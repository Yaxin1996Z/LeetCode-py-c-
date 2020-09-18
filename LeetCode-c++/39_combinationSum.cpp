#include<iostream>
#include<vector>
#include <algorithm>
#include<numeric>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, candidates, path);
        return result;
    }
    void backtrack(int start, int sum, int target, vector<int>& candidates, vector<int>& path)
    {
            for(int i=start; i<candidates.size(); ++i)
            {
                path.push_back(candidates[i]);
                sum += candidates[i];
                if(sum < target)
                    backtrack(i, sum, target, candidates, path);
                else
                {    
                    if(sum == target)
                        result.push_back(path);
                    path.pop_back();
                    sum -= candidates[i];
                    return;
                }
                path.pop_back();
                sum -= candidates[i];

            }
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> candidates = {2, 6, 3, 7};
    int target = 7;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    for(vector<int> x: res){
        cout << '[';
        for(int i: x){
            cout << i << ' ';
        }
        cout << ']' << endl;
    }
    system("pause");
    return 0;
}