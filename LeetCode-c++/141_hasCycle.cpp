#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution
{
    public:
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        if(!slow || !slow->next)
            return false;
        ListNode* fast = slow->next;
        while(fast && fast->next)
        {
            if(fast==slow)
                return true;
            else{
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return false;
    }
};

ListNode* createLinklist(vector<int>& nodelist, int pos)
{
    int len = nodelist.size();
    if(len==0)
    return nullptr;

    ListNode* head = new ListNode(nodelist[0]);
    ListNode* node = head;
    for(int i=1; i<len; ++i)
    {
        node->next = new ListNode(nodelist[i]);
        node = node->next;
    }
    if(pos == -1)
    return head;

    ListNode* tail = node;
    node = head;
    for(int i=0; i<pos; ++i)
    {
        node = node->next;
    }
    tail->next = node;
    return head;
}
int main(){

    vector<int> nodelist = {3,2,0,-4};
    ListNode* head = createLinklist(nodelist, 1);
    Solution solution = Solution();
    cout << solution.hasCycle(head);
    system("pause");
    return 0;
}