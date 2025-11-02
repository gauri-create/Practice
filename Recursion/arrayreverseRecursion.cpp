 #include<iostream>

 using namespace std;

 void arrayRev(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    arrayRev(i+1, arr, n);
 }

 int main(){
    int n;
    cout << "Enter number of array elements: "<<endl;
    cin >> n;
    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n ; i++) cin>>arr[i];
    arrayRev(0, arr, n);
    for(int i=0; i<n; i++) cout << arr[i]<<" ";

    return 0;
 }