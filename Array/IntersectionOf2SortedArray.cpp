#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionArr1(vector<int> arr1,vector<int>arr2,  int no1, int no2){
    vector<int> ans;
    int vis[no2]={0};
    for(int i=0; i<no1; i++){
        for(int j=0; j<no2; j++){
            if(arr1[i] == arr2[j] && vis[j] == 0){
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if(arr2[j] >arr1[i]) break;  
        }
    }
    return ans;
}

vector<int> intersectionArr2(vector<int> arr1, vector<int> arr2, int no1, int no2){
    vector<int> ans;
    int i=0; 
    int j=0;
    while(i<no1 && j<no2){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
} 

int main(){
    int no1, no2=0;
    cout<<"Enter Number of Array 1 elements:";
    cin>>no1;
    vector<int>arr1(no1);
    for(int i=0; i<no1; i++){
        cin>>arr1[i];
    }
    cout<<"Enter number of second array elements:";
    cin>>no2;
    vector<int>arr2(no2);
    for(int i=0; i<no2; i++){
        cin>>arr2[i];
    }
    // vector<int> ret = intersectionArr1(arr1, arr2, no1, no2);
    vector<int> ret = intersectionArr2(arr1, arr2, no1, no2);
    cout<<"Intersection of two array is: ";
    for(int i=0; i<ret.size();i++){
        cout<<ret[i]<<" ";
    }
    return 0;

}