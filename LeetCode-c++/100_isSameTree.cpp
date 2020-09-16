#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


struct TreeNode
{
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


TreeNode* createTree(vector<int>& nodeList)
{
    if(!nodeList.size()) return NULL;
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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    vector<int> nodeList1 = {1,2};
    vector<int> nodeList2 = {1,NULL, 2};
    TreeNode * p = createTree(nodeList1);
    TreeNode * q = createTree(nodeList2);
    Solution solution = Solution();
    cout << solution.isSameTree(p, q) << endl;;
    system("pause");
    return 0;
}