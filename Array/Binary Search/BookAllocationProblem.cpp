#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int fun(vector<int>arr, int pages){
    int student=1;
    int pagesStudent=0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent+arr[i]<=pages){ 
            pagesStudent+=arr[i];
        }
        else{
            student++;
            pagesStudent=arr[i];
        }
    }
    return student;
}
int BookAllocation(vector<int> arr, int n, int k){
    int low=*max(arr.begin(), arr.end());
    int high= accumulate(arr.begin(), arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int NoStu=fun(arr,mid);
        if(NoStu>k)low=mid+1;
        else high=mid-1;
    }
    return low;
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
    cout<<"Enter number of student: ";
    cin>>k;
    int ret=BookAllocation(arr, no , k);
    cout<<"student : "<<ret;
    return 0;
}