#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct TreeNode {
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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
        {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }    
        return dfs(root, p, q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(q->val < root->val)
            return dfs(root->left, p, q);
        else if(p->val > root->val)
            return dfs(root->right, p, q);
        else
            return root;
    }

};

int main()
{
    vector<int> nodeList = {6,2,8,1,4,7,9,NULL,NULL,3,5};
    TreeNode* root = createTree(nodeList);
    Solution solution = Solution();
    TreeNode* res = solution.lowestCommonAncestor(root, root->left, root->right);
    cout << res->val << endl;
    system("pause");
    return 0;
}