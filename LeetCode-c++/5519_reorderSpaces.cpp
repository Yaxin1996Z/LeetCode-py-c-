#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int countspace = 0;
        for(int i=0; i<text.size();)
        {
            string temp("");
            while(i<text.size() && text[i]!=' ')
            {
                temp += text[i++];
            }
            if(temp!="") words.push_back(temp);
            while(i<text.size() && text[i]==' ')
            {    
                i++;
                countspace++;
            }
        }
        string res("");
        if(words.size()==1)
         {   
             res += words[0];
             for(int i=0; i<countspace; ++i)
                res += " ";
            return res;
        }
        int sep = countspace / (words.size()-1);
        int last = countspace-sep*(words.size()-1);
        string space = "";
        for(int i=0; i<sep; ++i)
            space+=" ";
    
        for(int i=0; i<words.size()-1; ++i)
        {
            res +=words[i] ;
            res += space;
        }
        res += words[words.size()-1];
        for(int i=0; i<last; ++i)
            res += " ";
        return res;
    }
};

int main()
{
    string text = "a b c ";
    Solution solution = Solution();
    cout << solution.reorderSpaces(text);
    system("pause");
    return 0;
}