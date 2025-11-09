#include<iostream>
#include<vector> 
using namespace std;

//Bruteforce
double Median1(vector<int>arr1, int n1, vector<int>arr2, int n2){
    int n3=n1+n2;
    vector<int>arr3;
    
    int i=0, j=0;
    while(i<n1 && j<n2){
        if (arr1[i]<arr2[j]) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }
    while(i<n1) arr3.push_back(arr1[i++]);
    while(j<n2) arr3.push_back(arr2[j++]);
    if(n3%2==1){
        return arr3[n3/2];
    }
    else
        return double(((double)(arr3[n3/2])+(double)(arr3[n3/2 -1]))/2);
}

//Better
double Median2(vector<int> &arr1, int n1, vector<int> &arr2, int n2){
    int i=0;
    int j=0;
    int n=(n1+n2);
    int ind2=n/2;
    int ind1=ind2-1;
    int cnt=0;
    int ind1el=-1, ind2el=-1;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt == ind1) ind1el=arr1[i];
            if(cnt == ind2) ind2el=arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==ind1) ind1el=arr2[j];
            if(cnt==ind2) ind2el=arr2[j];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt== ind1) ind1el=arr1[i];
        if(cnt==ind2) ind2el=arr1[i];
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt==ind1) ind1el=arr2[j];
        if(cnt==ind2) ind2el=arr2[j];
        cnt++;
        j++;
    }
    if(n%2==1){
        return ind2el;
    }
    else
        return double(((double)(ind1el)+(double)(ind2el))/2);
}

//Optimal
double Median3(vector<int> &arr1, int n1, vector<int> &arr2, int n2){
    if(n1>n2) return Median2(arr2, n2, arr1, n1);
    int low=0, high=n1;
    int left = (n1+n1+1)/2;
    int n=n1+n2;
    while(low<=high){
       int mid1= (low+high)>>1;
       int mid2= left-mid1;
       int l1=INT_MIN, l2=INT_MIN;
       int r1=INT_MAX, r2=INT_MAX;
       if(mid1<n1) r1=arr1[mid1];
       if(mid2<n2) r2=arr2[mid2];
       if(mid1-1>=0) l1=arr1[mid1-1];
       if(mid2-1>=0) l2=arr2[mid2-1];
       if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1, l2);
            return ((double)(max(l1,l2))+(min(r1,r2)))/2.0;
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
    
}


int main(){
    int n1, n2;

    cout<<"Enter size of array 1: ";
    cin>>n1;
    vector<int> arr1(n1);
    cout<<"Enter element of array 1"<<endl;
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    cout<<"Enter size of array 2: ";
    cin>>n2;
    vector<int> arr2(n2);
    cout<<"Enter element of array 2"<<endl;
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    // double ret= Median1(arr1, n1, arr2, n2);
    // double ret= Median2(arr1, n1, arr2, n2);
    double ret= Median3(arr1, n1, arr2, n2);

    cout<<"Median of two sorted is: "<<ret;
}
