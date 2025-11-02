#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int Count(vector<int> nums, int n, int k){
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i=0; i<n;i++){
        xr=xr^nums[i];
        //k
        int  x=xr^k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    int no=0;
    int k=0;
    cout<<"Enter size of array: ";
    cin>>no;
    cout<<"Enter Array elements:"<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter value of K: ";
    cin>>k;
    int ret=Count(arr, no, k);
    cout<<" There are "<<ret<<"subarrays with given xor K "<<endl;
    return 0;

}