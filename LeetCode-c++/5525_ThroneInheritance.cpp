#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct Node
{
    string name;
    Node* father;
    Node* olderChild;
    Node* brother;
    Node(string x) : name(x), father(nullptr), olderChild(nullptr), brother(nullptr) {}
};

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> children; 
    unordered_set<string> dead;
    string king;
    vector<string> inheritanceOrder;
    ThroneInheritance(string kingName) {
        king = kingName;
        children[kingName] = {};
    }
    
    void birth(string parentName, string childName) {
        children[parentName].emplace_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        inheritanceOrder.clear();
        Successor(king);
        return inheritanceOrder;
    }

    void Successor(string x)
    {
        if(!dead.count(x))
            inheritanceOrder.emplace_back(x);
        for(string s:children[x])
            Successor(s);
    }
};

int main()
{

    ThroneInheritance* obj = new ThroneInheritance("king");
    obj->birth("king","andy");
    obj->birth("king", "bob");
    obj->birth("king", "catherine");
    obj->birth("andy", "mattew");
    obj->birth("bob", "alex");
    obj->birth("bob", "asha");
    obj->getInheritanceOrder();
    obj->death("bob");
    obj->getInheritanceOrder();
    vector<string> param_3 = obj->getInheritanceOrder();
    system("pause");
    return 0;
}