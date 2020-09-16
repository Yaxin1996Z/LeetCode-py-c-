#include<iostream>
#include<vector>
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
    if(nodeList[0]==NULL)
    {   
        return NULL;
    }
    TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nodeList[0];
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    int len = nodeList.size();
    while(!que.empty())
    {
        
        TreeNode *node = que.front();
        que.pop();
        if(node != NULL)
            {
                if(i==len)
                {
                    node->left = NULL;
                    node->right = NULL;
                    continue;
                }
                if(nodeList[i])
                {
                    TreeNode* n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                    n->val = nodeList[i];
                    node->left = n;
                    que.push(node->left);
                    
                }else{
                    node->left = NULL;
                }
                i++;
                if(i==len) 
                {
                    node->right = NULL;
                    continue;
                }
                if(nodeList[i])
                {
                    TreeNode* n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                    n->val = nodeList[i];
                    node->right = n;
                    que.push(node->right);
                }else{
                    node->right = NULL;
                }
                i++;
                if(i==len) continue;
            }
            
    }
    return root;
}

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> count;
        preOrderTraversal(root, 0, count, sums);
        vector<double> average;
        for(int i=0; i<count.size(); ++i){
            average.push_back(sums[i]/count[i]);
        }
        return average;
    }
    void preOrderTraversal(TreeNode* root, int level, vector<int>& count, vector<double>& sums)
    {
        if(!root)
            return;
        if(level<count.size())
        {
            sums[level] += root->val;
            count[level] += 1;
        }
        else
        {
            sums.push_back(root->val);
            count.push_back(1);
        }
        preOrderTraversal(root->left, level+1, count, sums);
        preOrderTraversal(root->right, level+1, count, sums);
    }
};

int main()
{
    vector<int> tree = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* root = createTree(tree);
    Solution solution = Solution();
    vector<double> res = solution.averageOfLevels(root);
    cout << '[';
    for(double x: res)
    {
        cout << x << ' ';
    }
    cout << ']' << endl;
    system("pause");
    return 0;
} 