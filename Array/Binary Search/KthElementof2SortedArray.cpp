#include<iostream>
#include<vector>
using namespace std;

int KthElement(vector<int> &arr1, int n1, vector<int> &arr2, int n2, int k){
    if(n1>n2) return KthElement(arr2, n2, arr1, n1, k);
    int low=max(k-n2,0), high=min(n1,k);
    int left = k;
    int n=n1+n2;
    while(low<=high){
       int mid1= (low+high)>>1;
       int mid2= left-mid1;
       int l1=INT_MIN, l2=INT_MIN;
       int r1=INT_MAX, r2=INT_MAX;
       if(mid1<n1) r1=arr1[mid1];
       if(mid2<n2) r2=arr2[mid2];
       if(mid1-1>=0) l1=arr1[mid1-1]; 
       if(mid2-1>=0) l2=arr2[mid2-1];
       if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
    
}


int main(){
    int n1, n2, k;

    cout<<"Enter size of array 1: ";
    cin>>n1;
    vector<int> arr1(n1);
    cout<<"Enter element of array 1"<<endl;
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    cout<<"Enter size of array 2: ";
    cin>>n2;
    vector<int> arr2(n2);
    cout<<"Enter element of array 2"<<endl;
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    cout<<"Enter value of k: ";
    cin>>k;

    int ret= KthElement(arr1, n1, arr2, n2, k);

    cout<<"Element at Kth index in two sorted array is: "<<ret;
}
