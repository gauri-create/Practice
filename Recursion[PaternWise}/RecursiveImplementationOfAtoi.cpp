#include<iostream>
#include<string>
using namespace std;

class Solution{
public:   
    int myAtoi(string input){
        int i=0;
        //skip leading spaces
        skipSpaces(input, i);

        //Handle sign
        int sign = 1;
        if(i<input.size() && (input[i]=='+' || input[i]=='-')){
            if(input[i]=='-') sign =-1;
            i++;
        }
        // Recursively extract digits
        long long val = parseDigits(input, i, 0);

        val *=sign;


        //clamp to integers range
        if(val<INT_MIN) return INT_MIN;
        if(val>INT_MAX) return INT_MAX;
        return (int)val;
    }
    private:
    void skipSpaces(const string &s, int &i){
        if(i>=s.size()||s[i]!=' ') return;
        i++;
        skipSpaces(s,i);
    }
    long long parseDigits(const string &s, int &i, long long current){
        if(i>=s.size()||!isdigit(s[i]))return current;
        int digit= s[i]-'0';

        //prevent overflow while building
        if(current>(LLONG_MAX-digit)/10){
            return LLONG_MAX;//we handle clamping later
        }
        current = current*10 + digit;
        i++;
        return parseDigits(s,i,current);
    }
};

int main(){
    Solution obj;
    string st;
    cout<<"Enter string"<<endl;
    getline(cin, st);
    int num=obj.myAtoi(st);
    cout<<num;
    return 0;
}