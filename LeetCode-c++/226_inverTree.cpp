#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
class Tree
{
    public:
    Tree(TreeNode* r): root(r){}
    void inorderTraversal(TreeNode* root)
    {
        if(!root)
            return;
        inorderTraversal(root->left);
        cout << root->val << ' ';
        inorderTraversal(root->right);
    }
    void preorderTraversal(TreeNode* root)
    {
        if(!root)
            return;
        cout << root->val << ' ';
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    private:
    TreeNode * root;
};
class Solution
{
    public:
    TreeNode* invertTree(TreeNode* root)
    {
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode * node = que.front();
            que.pop();
            if(!node) continue;
            if(node->left || node->right)
            {
                TreeNode * temp = node->left;
                node->left = node->right;
                node->right = temp;
                que.push(node->left);
                que.push(node->right);
            }
        }

        return root;
    }
    TreeNode* invertTree2(TreeNode* root)
    {
        if(!root) return NULL;
        TreeNode * left = invertTree(root->left);
        TreeNode * right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main()
{
    vector<int> nodeList = {4,2,7,1,3,6,9};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    Tree t = Tree(root);
    cout << "反转后先序遍历：";
    t.preorderTraversal(solution.invertTree(root));
    cout << endl;
    system("pause");
    return 0;
}