#include<iostream>
#include<vector>
using namespace std;


int Floor(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){ 
        int mid=(low+high)/2;
        //may be a answer
        if(arr[mid]<=target){
            ans=mid;
            //look for more small indes on left
            low=mid+1;
        }
        else{
            high=mid-1;//look for right
        }
    }
    return ans;
}

int Ceil(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        //may be a answer
        if(arr[mid]>=target){
            ans=mid;
            //look for more small indes on left
            high=mid-1;
        }
        else{
            low=mid+1;//look for right
        }
    }
    return ans;
}


int main(){
    int no=0;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array element:"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int target=0;
    cout<<"Enter target: ";
    cin>>target;
    int ret1=Floor(arr, no, target);
    int ret2=Ceil(arr, no, target);

    cout<<"Floor of "<<target<<" is "<<ret1<<" and ceil of "<<target<<" is "<<ret2;
    return 0;
}