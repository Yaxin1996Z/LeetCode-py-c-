#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* findkthNode(Node* head, int k)
{
    Node* node = head;
    while(--k){
        node = node->next;
    }
    return node;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;

        Node* node = head;
        while(node!=nullptr)
        {
            Node* cur = new Node(node->val);
            map[node] = cur;
            node = node->next;
        }
        node = head;
        while(node != nullptr)
        {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
            node = node->next;
        }
        return map[head];
    }
};

int main()
{
    Node* head = new Node(3);
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);

    head->next = node1;
    node1->next = node2;

    node1->random = head;

    Solution solution = Solution();
    Node* copy = solution.copyRandomList(head);
    system("pause");
    return 0;
}