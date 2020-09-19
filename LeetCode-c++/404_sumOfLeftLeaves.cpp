#include<vector>
#include<queue>
#include<iostream>
#include<string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Tree
{
    public:
    TreeNode * root;
    Tree(vector<int>& nodeList)
    {
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        createTree(nodeList);
    }

    void createTree(vector<int>& nodeList)
    {
        if(!nodeList[0])
            root = NULL;
        root->val = nodeList[0];
        root->left = NULL;
        root->right = NULL;
        int i = 1;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode * node = que.front();
            que.pop();
            if(nodeList[i])
            {
                TreeNode * n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                n->val = nodeList[i];
                n->left = NULL;
                n->right = NULL;
                que.push(n);
                node->left = n;
            }
            i++;
            if(i == nodeList.size())
                return;
            if(nodeList[i])
            {
                TreeNode * n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                n->val = nodeList[i];
                n->left = NULL;
                n->right = NULL;
                que.push(n);
                node->right = n;
            }
            i++;
            if(i == nodeList.size())
                return;
        }
    }

    void Traversal(int order = 0)
    {
        switch (order)
        {
        case 0:
            cout<< "先序遍历：";
            preorderTraversal(root);
            break;
        case 1:
            cout<< "中序遍历：";
            inorderTraversal(root);
            break;
        case 2:
            cout<< "后序遍历：";
            postorderTraversal(root);
            break;
        default:
            cout << "遍历选项不存在"<< endl;
            break;
        }
        cout << endl;
    }
    void preorderTraversal(TreeNode * root)
    {
        if(!root)
            return;
        cout<< root->val <<' ';
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void inorderTraversal(TreeNode * root)
    {
        if(!root)
            return;
        preorderTraversal(root->left);
        cout<< root->val <<' ';
        preorderTraversal(root->right);
    }
    void postorderTraversal(TreeNode * root)
    {
        if(!root)
            return;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        cout<< root->val <<' ';
    }
    // private:
    
};

class Solution
{
    public:
    int sumOfLeft = 0;
    int sumOfLeftLeaves(TreeNode* root)
    {
        dfs(root, false);
        return sumOfLeft;
    }
    void dfs(TreeNode* root, bool left)
    {
        if(!root) return;
        if(!root->left && !root->right && left)
            sumOfLeft += root->val;
        dfs(root->left, true);
        dfs(root->right, false);
    }
};

int main()
{
    vector<int> nodeList = {3, 9, 20, NULL, NULL, 15, 7};
    Tree t(nodeList);
    t.Traversal();
    Solution solution = Solution();
    cout << "左叶子之和：" << solution.sumOfLeftLeaves(t.root);
    system("pause");
    return 0;
}