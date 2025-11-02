#include<bits/stdc++.h>
using namespace std;
void Sortfor012a(vector<int> &arr){
    int i=0;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else if(arr[i]==2) cnt2++; 
    }
    for(i=0;i<cnt0; i++) arr[i]=0;
    for(i=cnt0;i<cnt0+cnt1; i++ ) arr[i]=1;
    for(i=cnt0+cnt1; i<cnt0+cnt1+cnt2; i++) arr[i]=2;
    
}

void Sortfor012b(vector<int> &arr, int no){
    int low=0;
    int mid=0;
    int high=no-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid== 1]){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

}


int main(){
    int no=0;
    cout<<"Enter size of array";
    cin>>no;

    vector<int> arr(no);
    cout<<"Enter array elements";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    Sortfor012a(arr);
    Sortfor012b(arr, no);
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}