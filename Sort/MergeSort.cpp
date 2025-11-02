#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    // [low...mid]
    // [mid+1...high]
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}
void MergeSort(vector<int> &arr, int low, int high){
   if(low == high) return;
   int mid = (low+high)/2;
   MergeSort(arr, low, mid);
   MergeSort(arr, mid+1, high);
   Merge(arr, low, mid, high);
}


int main(){
    int no=0;
    cout<<"Enter Number of elements: "<<endl;
    cin>>no;
    vector<int> arr;
    arr.reserve(no);//preaallocate memory 
    cout<<"Enter"<<no<<" elements: "<<endl;
    for(int i=0; i<no; i++){
        int val;
        cin>>val;
        arr.push_back(val);//Add the input value to the end of the vector
    }
    MergeSort(arr, 0, no-1);
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}