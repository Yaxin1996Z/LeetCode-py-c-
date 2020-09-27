#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        pair<int, int> times_profit = {-1, 0};
        int i = 0;
        int lastPeople = 0;
        int tempProfit = 0;
        while(i < n || lastPeople > 0)
        {
            if(i<n)
                lastPeople += customers[i];
            int curpeople = min(4, lastPeople);
            tempProfit += boardingCost * min(4, lastPeople) - runningCost;
            lastPeople -= curpeople;
            if(tempProfit > times_profit.second)
            {
                times_profit.first = i+1;
                times_profit.second = tempProfit;
            }
            i++;
        } 
        return times_profit.first;
    }
};

int main()
{
    vector<int> customers = {10,10,6,4,7};
    int boardingCost = 3;
    int runningCost = 8;

    Solution solution = Solution();
    cout << solution.minOperationsMaxProfit(customers, boardingCost, runningCost) << endl;

    system("pause");
    return 0;
}