#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        string LargeOddNum1(string &s){
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

        string LargeOddNum2(string &s){
            int n=s.size();
            int i=0;
            
            while(i<n && s[i]=='0')i++;
            s=s.substr(i);

            while(!s.empty() && (s.back()-'0')%2==0){
                s.pop_back();
            }
            return s;
        }
};
int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    Solution obj;
    // string ans = obj.LargeOddNum1(str);
    string ans = obj.LargeOddNum2(str);

    cout << "The lrgest number in string is: " << endl;
    cout << ans << endl;

    return 0;
}
