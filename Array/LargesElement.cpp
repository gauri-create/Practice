#include<iostream>
using namespace std;

int LargestElement(int arr[], int n){
    int largest=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>largest) 
          largest=arr[i];
    }
    return largest;
}

int main(){
    int no=0;
    cout<<"Enter number of array elements: "<<endl;
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int ret= LargestElement(arr, no);
    cout<<"Largest element is: "<<ret<<endl;
}