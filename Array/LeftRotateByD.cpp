#include<iostream>
#include<algorithm>
using namespace std;

void Rotate(int arr[], int no, int D){
    D=D%no;
    int temp[D]={0};
    for(int i=0; i<D; i++){
        temp[i]= arr[i];
    }
    for(int i=D; i<no; i++){
        arr[i-D]=arr[i];
    }
    for(int i=no-D;i<no;i++ ){
        arr[i]=temp[i-(no-D)];
    }

}

void Rotate1(int arr[], int no, int D){
    reverse(arr, arr+D);
    reverse(arr+D, arr+no);
    reverse(arr, arr+no);
}

int main(){
    int no=0;
    int D=0;
    cout<<"Enter Number of array element: ";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter the D place for rotation: ";
    cin>>D;
    // Rotate(arr, no, D);
    Rotate1(arr, no, D);
    cout<<"Array after left rotate by "<<D<<" place: "<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}