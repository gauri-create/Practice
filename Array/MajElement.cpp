//Majority element (n/3 times)
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> MajElement(vector<int> arr){
    vector<int>ls;
    map<int, int>mpp;
    int n=arr.size();
    int mini=(n/3)+1;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){
            ls.push_back(arr[i]);
        }
        if(ls.size()==2) break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}

//from N/2 times problem
vector<int>majorityElement(vector<int>nums){
    int cnt1=0, cnt2=0;
    int el1= INT_MIN;
    int el2=INT_MIN;
    int n=nums.size();

    for(int i=0; i<n; i++){
        if(cnt1 == 0 && el2!=nums[i]){
             cnt1=1;
             el1=nums[i];
        }
        else if(cnt2==0 && el1 != nums[i]){
            cnt2=1;
            el2=nums[i];
        }
        else if(nums[i]==el1)cnt1++;
        else if(nums[i]==el2)cnt2++;
        else{
            cnt1--, cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
         if(el1==nums[i]) cnt1++;
         if(el2 == nums[i])cnt2++;
    }
    int mini=(int)(n/3)+1;
    if(cnt1>=mini)ls.push_back(el1);
    if(cnt2>=mini)ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;
}

int main(){
    int no=0;
    cout<<"Enter size of array : ";
    cin>>no;
    vector<int> arr(no);
    cout<<"ENter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    // vector<int> ret= MajElement(arr);
    vector<int>ret=majorityElement(arr);
    for(auto i: ret){
     cout<<i<<" ";
    }
}