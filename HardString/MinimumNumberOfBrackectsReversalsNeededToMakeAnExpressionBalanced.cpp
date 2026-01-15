#include <iostream>
using namespace std;

class Solution
{
public:
    int countRev(string s)
    {
        int openBrackets = 0;
        int closeBrackets = 0;
        for (char ch : s)
        {
            if (ch == '(') openBrackets++;
            else{
                if(openBrackets>0) openBrackets--;
                else closeBrackets++;
            }
        }
        if((openBrackets+closeBrackets)%2!=0) return -1;
        return (openBrackets+1)/2+(closeBrackets+1)/2;
    }
};

int main()
{
    string s = "(()((()(())((";
    Solution obj;
    int ans = obj.countRev(s);
    cout << ans;
    return 0;
}