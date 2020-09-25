#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* createTree(vector<int> nodeList)
{
    int len = nodeList.size();
    if(len==0 || !nodeList[0])
        return nullptr;
    TreeNode* root = new TreeNode(nodeList[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i=1;
    while (i<len)
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

class Solution
{
    public:
    int count = 0;
    int cur = 0;
    int maxCount = 0;
    vector<int> findMode(TreeNode* root)
    {
        vector<int> res = {0};
        inorderTraversal(root, res);
        return res;
    }
    void inorderTraversal(TreeNode* root, vector<int>& res)
    {
        if(!root) return;
        inorderTraversal(root->left, res);
        if(root->val==cur){
            count ++;
        }
        else{
            cur = root->val;
            count = 1;
        }
        if(count==maxCount)
        {
            res.push_back(cur);
        }
        if(count > maxCount)
        {
            maxCount = count;
            res.clear();
            res.push_back(cur);
        }
        inorderTraversal(root->right, res);
    }
};

int main()
{
    vector<int> nodeList = {1, 1, 2, NULL, NULL, 2, 3};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    vector<int> res = solution.findMode(root);
    system("pause");
    return 0;
}