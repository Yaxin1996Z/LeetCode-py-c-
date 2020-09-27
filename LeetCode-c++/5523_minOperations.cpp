#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operations = 0;
        for(string s: logs)
        {
            if(s=="../")
                operations = max(0, operations-1);
            else if(s=="./")
                continue;
            else
            {
                operations++;
            }
            
        }
        return operations;
    }
};

int main()
{
    vector<string> logs = {"d1/","../","../","../"};
    // vector<string> logs = {"d1/","d2/","./","d3/","../","d31/"};
    Solution solution = Solution();
    cout << solution.minOperations(logs) << endl;
    system("pause");
    return 0;
}