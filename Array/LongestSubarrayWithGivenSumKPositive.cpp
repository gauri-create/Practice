#include<bits/stdc++.h>
using namespace std;

int LongestSubArray1(int arr[], int no, long long k){
    int len=0;
    for(int i=0; i<no; i++){
        int s=0;//sumof current subarray
        for(int j=i; j<no; j++){
            s+= arr[j];
            if(s==k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

int LongestSubArray2(int arr[], int no, long k){
    map< long long, int>preSumMap;
    long long sum=0;
    int maxLen=0;
    for(int i =0; i<no; i++){
        sum += arr[i];
        if(sum == k){
            maxLen=max(maxLen, i+1);
        }
        int rem=sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum] =i;
        }
    }
    return maxLen;
}

int LongestSubArray3(int arr[], int no, long long k){
    int left =0, right=0;
    long long sum = 0;
    int maxLen=0;
    while(right<no){
        while(left<=right && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left);
        }
        right++;
        if(right<no) sum += arr[right];
    }
    return maxLen;

}

int main(){
    int ret=0 ;
    long long k=0;
    int no = 0;
    cout<<"Enter array length: ";
    cin>>no;
    int arr[no];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter given sum: ";
    cin>>k;
    
    // ret=LongestSubArray1(arr, no, k);
    // ret=LongestSubArray2(arr, no, k);
    ret=LongestSubArray3(arr, no, k);
    cout<<"Length of longest subarray is "<<ret;
    return 0;
}