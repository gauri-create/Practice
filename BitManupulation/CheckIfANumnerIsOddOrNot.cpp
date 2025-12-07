#include<iostream>
using namespace std;

class Solution{
    public:
    bool isOdd(int n) {
        if(n%2==1)return true;
        return false;
    }
};

int main(){
    int n=8;
    Solution obj;
    bool ans = obj.isOdd(n);
    if(ans==true) cout<<"Odd";
    else cout<<"Even";
    return 0;
}