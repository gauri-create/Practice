#include<iostream>
#include<vector>
using namespace std;

int FirstOcc(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int LastOcc(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
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
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array element: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int target = 0;
    cout<<"Enter target value: ";
    cin>>target;

    int ret1=FirstOcc(arr, no, target);
    int ret2=LastOcc(arr, no, target);
    int cnt=(ret2-ret1)+1;
    cout<<"Total occurences of "<<target<<" is "<<cnt;
    return 0;
}
