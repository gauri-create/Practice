#include<iostream>
#include<vector>
using namespace std;

int Search(vector<int> arr, int no, int k){
    int low=0;
    int high=no-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid] == k)
             return mid;
             
        if(arr[low]==arr[mid]==arr[high]){
            low++, high--;
            continue;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
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
    int target;
    cout<<"Enter target: ";
    cin>>target;
    int ret=Search(arr, no, target);
    cout<<"The target "<<target<<" is found at "<<ret;
    return 0;
}