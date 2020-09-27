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

    TreeNode* createTree(vector<int> nodeList)
    {
        int len = nodeList.size();
        if(len==0 || !nodeList[0])
            return nullptr;
        root = new TreeNode(nodeList[0]);
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