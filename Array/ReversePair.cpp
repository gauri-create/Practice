#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
   vector<int> temp;//temporary array
   int left = low;//starting index of left half of arr
   int right = mid +1;//starting index of right half of arr
   //starting elementsin the temporary array in a sorted manner

   while(left<=mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
   }
   //if elemenr=ts on the left half are still left

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    } 

    //if elements on the right half are still left
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr
    for(int i=low; i<=high; i++){
         arr[i]=temp[i-low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high){
    int cnt=0;
    int right=mid+1;
     for(int i= low; i<=mid; i++){
         while(right<= high && arr[i]>2*arr[right]) right++;
         cnt +=(right-(mid+1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low,int high){
    int cnt=0;
   if(low>=high) return 0;
   int mid = (low+high)/2;
   cnt+=mergeSort(arr, low, mid);//left half
   cnt+=mergeSort(arr, mid+1, high);//right half
   cnt+=countPairs(arr, low, mid, high);
   merge(arr, low, mid, high);//merging sorted halves
   return cnt;
}

int ReversePair(vector<int> &arr, int n ){
    return mergeSort(arr, 0, n-1);
    
}

int main(){
    int no=0;
    cout<<"Enter size of array: ";
    cin>>no;
    cout<<"Enter array elements:"<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
         cin>>arr[i];
    }
    int ret=ReversePair(arr, no);
    cout<<"In this array total revrse pairs are: "<<ret<<endl;
    return 0;
}
