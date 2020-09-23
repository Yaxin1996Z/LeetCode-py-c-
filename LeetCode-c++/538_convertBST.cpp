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

TreeNode* createTree(vector<int>& nodeList)
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
    int presum = 0;
    TreeNode * convertBST(TreeNode* root)
    {
        postTraversal(root);
        return root;
    }
    void postTraversal(TreeNode* root)
    {
        if(!root)
            return;
        postTraversal(root->right);
        root->val += presum;
        presum = root->val;
        postTraversal(root->left);
    }
};

int main()
{
    vector<int> nodeList = {5,2,13};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    Tree t = Tree(root);
    cout << "累加后先序遍历：";
    t.preorderTraversal(solution.convertBST(root));
    cout << endl;
    system("pause");
    return 0;
}