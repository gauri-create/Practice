#include<iostream>
#include<vector>
using namespace std;

bool CanWePlace(vector<int> &stalls, int dist, int cows){
    int cntCows=1, last=stalls[0];
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-last>=dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}

int Kmissing(vector<int> arr, int n, int k){
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(CanWePlace(arr, mid, k)==true)low=mid+1;
        else high=mid-1;
    }
    return high;
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
    cout<<"Enter no. of cows : ";
    cin>>k;
    int ret=Kmissing(arr, no , k);
    cout<<"distance is: "<<ret;
    return 0;
}