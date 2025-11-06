#include<iostream>
using namespace std;

int func(int mid, int n, int m){
     long long ans=1;
     for(int i=1; i<=n; i++){
         ans=ans*mid;
         if(ans>m) return 2;
    }    
    if(ans==m) return 1;
    return 0;

}

int NthRoot(int n, int m){
    int low=1; int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=func(mid, n, m);
        if(midN==1){
            return mid;
        }
        else if(midN == 0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    int n, m;
    cout<<"Enter number: ";
    cin>>m;
    cout<<"Enter value of N for Nth root: ";
    cin>>n;
    int ret=NthRoot(n,  m);
    cout<<" Root is : "<<ret;
    return 0;

}