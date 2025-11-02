#include <bits/stdc++.h>
using namespace std;

vector<int> LeadersInArray(vector<int> &arr, int n){
     vector<int> ans;
     int maxi = INT_MIN;
     for(int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
             ans.push_back(arr[i]);
        }
        maxi=max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
     int no=0;
     cout<<"Entre size of array: ";
     cin>>no;
     vector<int> arr(no);
     cout<<"Enter array elements: "<<endl;
     for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    vector<int> ret= LeadersInArray(arr, no);
    cout<<"Leaders in an array are: ";
    for(auto i : ret) cout<<i<<" ";
    return 0;
}