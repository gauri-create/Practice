#include<iostream>
#include<vector>
using namespace std;

//Recursion
int fibo(int n){
    if(n<=1) return n;
    return fibo(n-1)+fibo(n-2);
}

//Memoization
int f(int n, vector<int> &dp){
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n]=f(n-1, dp)+f(n-2, dp);
}

//Tabulation
int fib(int n){
    int prev2=0;
    int prev1=1;
    for(int i=2; i<=n; i++){
        int curi=prev1+prev2;
        prev2=prev1;
        prev1=curi;
    }
    return prev1;
}

int main(){
   int n=5;
   vector<int>dp(n+1, -1);
   int ans=fibo(n);
//    int ans=f(n, dp);
//    int ans=fib(n);
   cout<<ans;
   return 0;
}