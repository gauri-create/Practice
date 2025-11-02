#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i=low;
    int j= high;
    while(i<j){
        while(arr[i]<= pivot && i<=high-1) i++;
        while(arr[j]> pivot && j>=low+1) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(vector<int> &arr,int low, int high){
    if(low<high){
        int PIndex = Partition(arr, low, high);
        QuickSort(arr, low, PIndex-1);
        QuickSort(arr, PIndex+1, high);
    }
}
int main(){
    int no=0;
    cout<<"Enter the number of array elements: ";
    cin>>no;
    vector<int> arr;
    arr.reserve(no);//preallocate memory
    cout<<"Enter arry aelements";
    for(int i=0;i<no; i++)
    {
    int val;
    cin>>val;
    arr.push_back(val);
    }
    QuickSort(arr, 0, no-1);
    for(int i=0; i<no; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}