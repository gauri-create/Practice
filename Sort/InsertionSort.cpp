#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    for(int i=0;i<n; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
        
    }
}

int main(){
    int no;
    cout<<"Enter array size"<<endl;
    cin>>no;
    int arr[no];
    cout<<"Enter array elements"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    InsertionSort(arr, no);
    cout<<"Sorted array by Insertion Sort"<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
}