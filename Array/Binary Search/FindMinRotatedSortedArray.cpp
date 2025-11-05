#include<iostream>
#include<vector>
using namespace std;

int MinSearch(vector<int> arr, int no){
    int low=0;
    int high=no-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;


        //Search spaceis already sorted
        //then always arr[low] is will be smaller
        //in that seach space
        if(arr[low] <= arr[high]){
            ans=min(ans, arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
              ans=min(ans, arr[low]);
              low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(ans, arr[mid]);
        }

    }
    return ans;

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
    cout<<"The minimum element in this array is "<<ret;
    return 0;
}