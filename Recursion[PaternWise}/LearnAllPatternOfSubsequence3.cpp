#include<iostream>
#include<vector>
using namespace std;
//print count of ans
int printS(int ind, vector<int>&ds, int s, int sum, int arr[], int n){
    if(ind==n){
        //condition satisfied
        if(s==sum) return 1;
        else
            return 0;
    }

    s+=arr[ind];
    int l=printS(ind+1, ds, s, sum, arr, n);
    s-=arr[ind];
    //not pick
    int r= printS(ind+1, ds, s, sum, arr, n);
    return l+r;
}

int main(){

    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    int ans = printS(0,ds,0,sum,arr,n);
    cout<<ans;
    return 0;
}
