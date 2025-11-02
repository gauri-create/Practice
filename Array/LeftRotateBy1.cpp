#include<iostream>
using namespace std;

void Rotate(int arr[], int no){
    int temp=arr[0];
    for(int i=1; i<no; i++){
        arr[i-1]=arr[i];
    }
    arr[no-1]=temp;
}

int main(){
    int no=0;
    cout<<"Enter Number of array element: ";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    Rotate(arr, no);
    cout<<"Array after left rotate by one place: "<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}