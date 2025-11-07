#include<iostream>
#include<vector>
using namespace std;

int Kmissing(vector<int> arr, int n, int k){
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing= arr[mid]-(mid+1);
        if(missing<k)low=mid+1;
        else high=mid-1;
    }
    return low+k;
}

int main(){
    int no=0;
    int k;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array element: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter kth value: ";
    cin>>k;
    int ret=Kmissing(arr, no , k);
    cout<<"Missing number is: "<<ret;
    return 0;
}