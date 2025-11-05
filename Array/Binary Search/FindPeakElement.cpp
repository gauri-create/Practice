#include<iostream>
#include<vector>
using namespace std;

int MinSearch(vector<int> arr, int n){
    if(n==1) return 0;
    if(arr[0]> arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low=1;
    int high=n-2;
   
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
             return mid;
        }
        else if( arr[mid]>arr[mid-1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;

}

int main(){
     int no=0;
     cout<<"Enter size of array: ";
     cin>>no;
     vector<int> arr(no);
     cout<<"Enter array element: "<<endl;
     for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    
    int ret=MinSearch(arr, no);
    cout<<"The index of peak of array is : "<<ret;

    return 0;
}