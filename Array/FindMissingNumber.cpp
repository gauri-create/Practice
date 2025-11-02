#include<iostream>
using namespace std;

int FindMissingNumber1(int arr[], int no){
    for(int i=1; i<no; i++){
        int flag=0;
        for(int j=0; j<no-1; j++){
            if(arr[j]==i){
                flag =1;
                break;
            }
        }
        if(flag==0) return i;
    }
    return no;
}

int FindMissingNumber2(int arr[], int no){
    int i=0;
    int j=1;
    while(i<no-1){
        if(arr[i]!=j) break;
        i++;
        j++;
    }
    return j;
}

int SumMethod(int arr[], int no){
    int sum=(no*(no+1))/2;
    int s=0;
    for(int i=0; i<no-1; i++){
        s=s+arr[i];
    }
    return sum-s;
}

int XORMethod(int arr[], int no){
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0; i<no-1; i++){
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^no;
    return xor1^xor2;
}

int main(){
    int no;
    cout<<"Enter number of elements :";
    cin>>no;
    cout<<"Enter array elements: "<<endl;
    int arr[no-1];
    for(int i=0; i<no-1; i++){
        cin>>arr[i];
    }
    // int ret = FindMissingNumber1(arr, no);
    // int ret = FindMissingNumber2(arr, no);
    // int ret = SumMethod(arr, no);
    int ret = XORMethod(arr, no);
    cout<<"Missing number is: "<<ret<<endl;
    
    return 0;
}