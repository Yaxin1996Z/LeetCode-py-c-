#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
    unordered_map<int, int> map;
    vector<int> post;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        
        for(int i=0; i<inorder.size(); ++i)
        {
            map.insert(make_pair(inorder[i], i));
        }
        post = postorder;
        TreeNode* root = helper(0, inorder.size()-1, 0, postorder.size()-1);

        return root;
    }
    TreeNode* helper(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd)
    {
        if(inorderEnd < inorderStart || postorderEnd < postorderStart)
            return nullptr;
        int rootVal = post[postorderEnd];
        int rootIndexInInorderArray = map[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(inorderStart, rootIndexInInorderArray-1, postorderStart, postorderStart+rootIndexInInorderArray-inorderStart-1);
        root->right = helper(rootIndexInInorderArray+1, inorderEnd, postorderStart+rootIndexInInorderArray-inorderStart, postorderEnd-1);
        return root;
    }
};

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution solution = Solution();
    TreeNode* tree = solution.buildTree(inorder, postorder);
    system("pause");
    return 0;
}