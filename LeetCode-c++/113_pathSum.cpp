#include<vector>
#include<iostream>
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
    int i=1;
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(nodeList[0]);
    que.push(root);
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
        if(++i==len)
            break;
        if(nodeList[i])
        {
            TreeNode* n = new TreeNode(nodeList[i]);
            node->right = n;
            que.push(n);
        }
        if(++i==len)
            break;
    }
    return root;
}

class Solution
{
    public:
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<int> path;
        dfs(path, sum, root);
        return result;
    } 
    void dfs(vector<int>& path, int sum, TreeNode* root)
    {
        if(!root)
            return;
        path.push_back(root->val);
        sum-=root->val;
        if(sum==0 && !root->left && !root->right)
        {    
            result.push_back(path);
            path.pop_back();
            return;
        }
        dfs(path, sum, root->left);
        dfs(path, sum, root->right);
        path.pop_back();
    }
};

int main()
{
    vector<int> nodeList = {-2,NULL,-3};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    vector<vector<int>> res = solution.pathSum(root, 22);

    for(vector<int> x: res)
    {
        cout << '[';
        for(int i:x)
        {
            cout << i << ' ';
        }
        cout << ']' << endl;
    }
    system("pause");
    return 0;
}