#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int SumByD(vector<int> &arr, int div){
    int sum=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        sum+= ceil((double)(arr[i])/(double)(div));
    }
    return sum;
}

int SmallestDivisor(vector<int> &arr, int limit){
    int low=1, high=*max_element(arr.begin(), arr.end());
    while(low<=high){
         int mid=(low+high)/2;
         if(SumByD(arr, mid) <=limit){
             high=mid-1;
        }
        else
            low=mid+1;
    }
    return low;
}


int main(){
    int no=0;
    int m=0;
    cout<<"Enter array size ";
    cin>>no;
    cout<<"Enter array element :"<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter  threshold: ";
    cin>>m;
    int ret=SmallestDivisor(arr, m);
    cout<<"The list divisor is : "<<ret;
    return 0;
}