#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Nested loop
int CountInversion1(vector<int> arr){
    int cnt=0;
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}
//Merge Sort method

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int>temp;//temporary array
    int left=low;//starting index of left half of arr
    int right=mid+1;//starting index of right half of arr
    
    //sorting elements in the temporary array in a sorted manner
    int cnt=0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        //right is smaller
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    //if elements on the left half still left

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    //if elements on the right half still left
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    //transfering all elements from temporary to arr
    for(int i=low; i<=high; i++){
       arr[i]=temp[i-low];
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;

    cnt+=mergeSort(arr, low, mid);//left half
    cnt+=mergeSort(arr, mid+1, high);//right half
    cnt+=merge(arr, low, mid, high);//merging sort halves
    return cnt;

}

int  CountInversion2(vector<int>arr){
    int n=arr.size();
    return mergeSort(arr, 0, n-1);
}

int main(){
    int no=0;
    cout<<"Enter array size: ";
    cin>> no;
    cout<<"Enter array element: "<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    // int ret=CountInversion1(arr);
    int ret=CountInversion2(arr);

    cout<<"The count inversion is "<<ret;
    return 0;
}