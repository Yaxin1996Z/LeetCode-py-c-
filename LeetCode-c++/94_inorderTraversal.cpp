#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* createTree(vector<int>& nodeList)
{
    if(!nodeList[0]) return NULL;
    TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nodeList[0];
    root->left = NULL;
    root->right = NULL;
    int i = 1;
    queue<TreeNode *> que;
    que.push(root);
    int len = nodeList.size();
    while(i<len)
    {
        TreeNode *node = que.front();
        que.pop();
        if(node!=NULL)
        {
            if(nodeList[i])
            {
                TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                n->val = nodeList[i];
                n->left = NULL;
                n->right = NULL;
                node->left = n;
                que.push(node->left);
            }
            i++;
            if(i==len) break;
            if(nodeList[i])
            {
                TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                n->val = nodeList[i];
                n->left = NULL;
                n->right = NULL;
                node->right = n;
                que.push(node->right);
            }
            i++;
            if(i==len) break;
        }
    }
    return root;
}

class Solution
{
    public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
    
};

int main()
{
    vector<int> treelist = {1, NULL, 2, 3};
    TreeNode* root = createTree(treelist);
    Solution solution = Solution();
    vector<int> res = solution.inorderTraversal(root);

    cout << '[';
    for(int x:res)
    {
        cout << x <<' ';
    }
    cout << ']' << endl;
    system("pause");
    return 0;
}