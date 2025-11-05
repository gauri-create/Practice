#include<iostream>
#include<vector>
using namespace std;

int MinSearch(vector<int> arr, int no){
    int low=0;
    int high=no-1;
    int index=-1;
    int ans=INT_MAX;


    while(low<=high){
        
        int mid=(low+high)/2;
        //Search spaceis already sorted
        //then always arr[low] is will be smaller
        //in that seach space
        if(arr[low] <= arr[high]){
            if(arr[low]<ans){
                 index=low;
                 ans=arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid]){
             if(arr[low]<ans){
                 index=low;
                 ans=arr[low];
            }
            low=mid+1;
        }
        else{
            high=mid-1;
            if(arr[mid]<ans){
                 index=mid;
                 ans=arr[mid];
            }
        }

    }
    return index;

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