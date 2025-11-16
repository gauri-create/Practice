#include<iostream>
using namespace std;

class Solution{
public:
    int Atoi(string s){
        char sign ='+';
        int result=0;
        bool startDigit=false;

        for(int  i=0; i<s.length(); i++){
            if(!startDigit && s[i]==' ') continue;

            if(!startDigit && (s[i]=='+' || s[i]=='-')){
                sign=(s[i] == '-') ? '-' : '+';
                startDigit = true;
                continue;
            }
            
            if('0'<=s[i] && s[i]<='9'){
                startDigit = true;
                int temp=s[i]-'0';
                result=result*10+temp;
                continue;
            }
            
             break;

        }
        if(sign=='-')  return -result;
        return result;
    }
};

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    Solution obj;
    int ret = obj.Atoi(s);
    cout<<"String to integer is : "<<ret;
    return 0;
}