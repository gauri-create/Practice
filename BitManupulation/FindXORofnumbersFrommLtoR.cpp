#include<iostream>
using namespace std;

class Solution{
    public:
    int findXOR(int L, int R){
        return func(L-1)^func(R);
    }

    int func(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }
};

int main(){
    Solution obj;
    int L=1, R=3;
    int ans= obj.findXOR(L,R);
    cout<<ans;
    return 0;
}