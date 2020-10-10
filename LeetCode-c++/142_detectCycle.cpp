#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
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

class Solution
{
    public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        if(!slow || !slow->next)
            return nullptr;
        ListNode* fast = slow;
        while(true)
        {
            if(!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                break;   
        }
        fast = head;
        while (fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* detectCycle2(ListNode* head)
    {
        // 空间占用过大
        if(!head || !head->next) return nullptr;
        vector<ListNode*> que;
        while (head)
        {
            que.push_back(head);
            head = head->next;
            for(int i=0; i<que.size(); ++i)
            {
                if(head==que[i])
                    return que[i];
            }
        }
        return nullptr;
    }
};


int main(){
    vector<int> nodelist = {1,2};
    ListNode* head = createLinklist(nodelist, 0);
    Solution solution = Solution();
    ListNode* res = solution.detectCycle(head);
    if(res)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;
    system("pause");
    return 0;
}