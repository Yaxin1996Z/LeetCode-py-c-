#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct TreeNode
{
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TreeNode createTree(int val)
{
    if(val!=-1)
    return TreeNode(val);
}
int main()
{
    int nodes[100];
    string node;
    int index = 0;
    while (cin>>node)
    {
        if(node=="null")
            nodes[index++] = -1;
        else
        {
            nodes[index++] = stoi(node);
        }
        char ch = getchar();
        if(ch=='\n') break;
    }
    
    for(int i=0; i<index; ++i)
    {    
        TreeNode node = TreeNode();
        node = createTree(nodes[i]);
    }

    system("pause");
    return 0;
}