#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

TreeNode* createTree(vector<int>& nodeList)
{
    int len = nodeList.size();
    if(len==0 || !nodeList[0])
        return nullptr;
    TreeNode* root = new TreeNode(nodeList[0]);
    int i=1;
    queue<TreeNode*> que;
    que.push(root);
    while (i<len)
    {
        TreeNode* node = que.front();
        que.pop();
        if(nodeList[i])
        {
            node->left = new TreeNode(nodeList[i]);
            que.push(node->left);
        }
        if(++i==len) break;
        if(nodeList[i])
        {
            node->right = new TreeNode(nodeList[i]);
            que.push(node->right);
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode* node = root;
        while (node)
        {
            if(!node->left && val < node->val)
            {    
                node->left = new TreeNode(val);
                break;
            }
            if(!node->right && val > node->val)
            {
                node->right = new TreeNode(val);
                break;
            }
            if(val < node->val)
                node = node->left;
            else
                node = node->right;
        }
        return root;
    }
    TreeNode* insertIntoBST2( TreeNode* root, int val)
    {
        if(!root)
            return new TreeNode(val);
        if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int main()
{
    vector<int> nodeList = {4,2,7,1,3};
    int val = 8;
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    TreeNode* res = solution.insertIntoBST(root, val);
    inorderTraversal(res);
    system("pause");
    return 0;
}