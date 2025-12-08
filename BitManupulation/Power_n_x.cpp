#include<iostream>
using namespace std;

class Solution{
    public:
    double myPow(double x, int n){
        int m;
        if(n<0){
             m=n;
            n=-n;
        }    
        double ans=1;
        while(n>0){
            if(n%2==1){
                ans *= x;
                n=n-1;
            }
            else{
                n=n/2;
                x= x*x;
            }
            if(m<0) ans=1.0/ans;
        }
        return ans;
    }

};

int main(){
    double x=2.0000; 
    int n=-2;
    Solution obj;
    double ans= obj.myPow(x,n);
    cout<<ans<<endl;
    return 0;
}