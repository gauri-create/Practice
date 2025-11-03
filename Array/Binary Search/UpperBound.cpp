#include<iostream>
#include<vector>
using namespace std;

int UpperBound(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low <= high){
       int mid=(low+high)/2;
       if(arr[mid]>target) {
           ans=mid;
           high=mid-1;
       }
       else{
           low=mid+1;
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
    
    int ret2=UpperBound(arr, no, target);
    cout<<"Upper bound is: "<<ret2;
    return 0;

}