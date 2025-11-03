#include<iostream>
#include<vector>
using namespace std;


int LowerBound(vector<int> arr, int n, int target){
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
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int target=0;
    cout<<"Enter target value: ";
    cin>>target;
    int ret=LowerBound(arr, no, target);
    cout<<"At index: "<<ret;
    return 0;

}