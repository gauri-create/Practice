#include<iostream>
#include<vector>
using namespace std;

int FindX1(vector<int> arr, int no, int target){
    int low=0;
    int high=no-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]<target) low=mid+1;
        else if(target<arr[mid]); high=mid-1;

    }
    return -1;
}


int search(vector<int> &arr, int low, int high, int target){
   
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) 
       return search(arr, low, mid -1, target);
    else if(arr[mid]<target)
       return search(arr, mid+1, high, target);

    return 0;
}

int FindX2(vector<int> &arr, int n, int target){
    return search(arr, 0, n-1, target);
}

int main (){
     int no=0;
    cout<<"Enter size of "<<endl;
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array element: "<<endl;
    for(int i=0;i<no; i++){
        cin>> arr[i];
    }
    int target=0;
    cout<<"Enter target to be found:"<<endl;
    cin>>target;
    // int ret=FindX1(arr, no, target);
    int ret=FindX2(arr,no , target);

    cout<<"Binary search to find X is found at"<<ret<<endl;
    return 0;
}