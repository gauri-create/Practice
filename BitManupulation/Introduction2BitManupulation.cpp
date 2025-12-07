#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
    string convert2Binary(int n){
        string result="";
        while(n>0){
            if(n%2==1)result+='1';
            else result+='0';
            n=n/2;
        }
        reverse(result.begin(), result.end());
        return result;
    }


    int convert2decimal(string s){
        int num=0;
        for(char c: s){
            num=num*2 +(c-'0');
        }
        return num;
    }

    string OnesComplement(string s){
        string result="";
        for(char c:s){
            if(c=='0') result+='1';
            else result+='0';
        }
        return result;
    }

    string TwosComplement(string s){
        string result="";
        int i=s.size()-1;
        while(s[i]=='0' && i>=0){
            result+='0';
            i--;
        }
        if(i>=0){
            result+='1';
            i--;
        }
        while(i>=0){
            if(s[i]=='0') result+='1';
            else result+='0';
            i--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution obj;
    int n=16;
    string s="1010";
    // string ans= obj.convert2Binary(n);
    // cout<<n<<endl;
    // cout<<ans;

    // int res=obj.convert2decimal(s);
    // cout<<res;
    // string ans1=obj.OnesComplement(s);
    // cout<<ans1<<endl;
    string ans2=obj.TwosComplement(s);
    cout<<s<<endl;
    cout<<ans2<<endl;

    return 0;
}