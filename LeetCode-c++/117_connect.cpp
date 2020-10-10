#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node* createTree(vector<int> nodeList)
{
    int len = nodeList.size();
    if(len==0 || !nodeList[0])
        return nullptr;
    Node* root = new Node(nodeList[0]);
    queue<Node*> que;
    que.push(root);
    int i=1;
    while (i<len)
    {
        Node* node = que.front();
        que.pop();
        if(nodeList[i])
        {
            Node* n = new Node(nodeList[i]);
            node->left = n;
            que.push(n);
        }
        if(++i==len) break;
        if(nodeList[i])
        {
            Node* n = new Node(nodeList[i]);
            node->right = n;
            que.push(n);
        }
        if(++i==len) break;
    }
    return root;
}

class Solution
{
    public:
    Node* connect(Node* root)
    {
        if(!root)
            return nullptr;
        Node* node = root;
        while(node)
        {
            Node* head = new Node();
            Node* temp = head;
            while(node)
            {
                if(node->left)
                {
                    temp->next = node->left;
                    temp = node->left;
                }
                if(node->right)
                {
                    temp->next = node->right;
                    temp = node->right;
                }
                node = node->next;
            }
            node = head->next;
            delete head;
        }
        return root;
    }
};

int main()
{
    vector<int> nodeList = {1,2,3,4,5,NULL,7};
    Node* root = createTree(nodeList);
    Solution solution = Solution();
    Node* res = solution.connect(root);
    system("pause");
    return 0;
}