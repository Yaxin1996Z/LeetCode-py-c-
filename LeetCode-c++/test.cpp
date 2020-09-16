#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(){
    TreeNode t = TreeNode(5);
    TreeNode *p = &t;
    system("pause");
}