#include<iostream>

using namespace std;

int Sqrt(int no){
    int low=1;
    int high=no-1;
    int ans=1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(mid*mid<=no){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int no=0;
    cout<<"Enter number whose squre root has to be found: ";
    cin>>no;
    int ret= Sqrt(no);
    cout<<"Squre root of "<<no<<" is "<<ret;
    return 0;
}