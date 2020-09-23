#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(vector<int> nodeList)
{
    if(nodeList.size()==0)
        return nullptr;
    TreeNode* root = new TreeNode(nodeList[0]);
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    int len = nodeList.size();
    while(i<len)
    {
        TreeNode* node = que.front();
        que.pop();
        if(nodeList[i])
        {
            TreeNode* n = new TreeNode(nodeList[i]);
            node->left = n;
            que.push(n);
        }
        if(++i==len) break;
        if(nodeList[i])
        {
            TreeNode* n = new TreeNode(nodeList[i]);
            node->right = n;
            que.push(n);
        }
        if(++i==len) break;

    }
    return root;
}

void inorderTraversal(TreeNode* root)
{
    if(!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

class Solution
{
    public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        TreeNode* t3 = Traversalnode(t1, t2);
        return t3;
    }
    TreeNode* Traversalnode(TreeNode* t1, TreeNode* t2)
    {
        TreeNode* t3 = new TreeNode(0);
        if(t1 && t2)
        {
            t3->val = t1->val + t2->val;
            t3->left = Traversalnode(t1->left, t2->left);
            t3->right = Traversalnode(t1->right, t2->right);
        }
        if(!t1)
            t3 = t2;
        if(!t2)
            t3 = t1;
        return t3;
    }
};

int main()
{
    TreeNode* t1 = createTree(vector<int>{1,3,2,5});
    TreeNode* t2 = createTree(vector<int>{2,1,3,NULL,4,NULL,7});
    Solution solution = Solution();
    TreeNode* res = solution.mergeTrees(t1, t2);
    inorderTraversal(res);
    system("pause");
    return 0;
}