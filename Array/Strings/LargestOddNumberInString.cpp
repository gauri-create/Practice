#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        string LargeOddNum(string &s){
            int n=s.size();
            int i=0;
            string str;
            while(i<n && str[i]=='0')i++;
            str=s.substr(i);

            while(!str.empty() && (str.back()-'0')%2==0){
                str.pop_back();
            }
            return str;
        }
};
int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    Solution obj;
    string ans = obj.LargeOddNum(str);

    cout << "The lrgest number in string is: " << endl;
    cout << ans << endl;

    return 0;
}
