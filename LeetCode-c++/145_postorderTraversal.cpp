#include<vector>
#include<iostream>
#include<queue>
#include<stack>

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
    if(len==0||!nodeList[0])
        return nullptr;
    TreeNode* root = new TreeNode(nodeList[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (i < len)
    {
        TreeNode* node = que.front();
        que.pop();

        if(nodeList[i])
        {
            node->left = new TreeNode(nodeList[i]);
            que.push(node->left);
        }
        if(++i==len)
            break;
        if(nodeList[i])
        {
            node->right = new TreeNode(nodeList[i]);
            que.push(node->right);
        }
        if(++i==len)
            break;
    }
    return root;
    
}

class Solution
{
    public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        while (node || !stk.empty())
        {
            while(node)
            {    
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            if(!node->right || pre==node->right)
            {
                result.push_back(node->val);
                pre = node;
                stk.pop();
                node =nullptr;
            }
            else
                node = node->right;
        }
        return result;
    }
    
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node || !stk.empty())
        {
            while(node)
            {    
                stk.push(node);
                result.push_back(node->val);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
            
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node || !stk.empty())
        {
            while(node)
            {    
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
};

int main()
{
    vector<int> nodeList = {1,2,3,4,5,6,7};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    vector<int> res = solution.postorderTraversal(root);
    for(int x : res)
        cout << x << ' ';
    system("pause");
    return 0;
}