#include<iostream>
#include<vector>
using namespace std;

int MinSearch(vector<int> arr, int n){
    if(n==1) return arr[0];
    if(arr[0]!= arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1;
    int high=n-2;
   
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
             return arr[mid];
        }
        //we are in left
        if((mid%2 == 1 && arr[mid] ==arr[mid-1])||(mid % 2 == 0) && arr[mid]==arr[mid+1]){
             low=mid+1;
        }
        //we are on right
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
    cout<<"The no. of sorted array rotation are : "<<ret;
    return 0;
}