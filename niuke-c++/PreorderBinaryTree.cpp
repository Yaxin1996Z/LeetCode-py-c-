#include <iostream>
#include <vector>
using namespace std;


class Treenode
{
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    vector<int> preorderTraversal(Treenode* root)
    {
        vector<int> res;
        return res;
    }
};

int main()
{
    Solution solution = Solution();
    int len;
    cout << "输入长度：" ;
    cin >> len;
    string eachnode[len];

    cout << endl << endl<< "输入每个节点的值，用空格隔开：";
    for(int i=0; i<len; ++i)
    {
        cin >> eachnode[i];
    }
    cout << "-------------------" << endl;

    for(int i=0; i<len; ++i)
    {
        cout << eachnode[i] <<'\t';
    }
    cout << endl;
    
    // Treenode root = Treenode(1);
    system("pause");
    return 0;
}