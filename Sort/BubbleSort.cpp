#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    int k=1;
    for(int i=n-1; i>=0; i--){
        for(int j= 0; j<=i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
         cout<<"Step "<< k <<endl;
            for(int i=0; i<n; i++){
             cout<<arr[i]<<endl;
            }
            k++;
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
    BubbleSort(arr, no);
    cout<<"Sorted array by Bubble Sort"<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
}