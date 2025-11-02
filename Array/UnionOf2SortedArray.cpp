#include<bits/stdc++.h>
using namespace std;

vector<int> Union1(int arr1[], int arr2[], int no1, int no2){
    set<int>st;
    for(int i=0; i<no1; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<no2; i++){
        st.insert(arr2[i]);
    }
    vector<int> result;
    for (auto it = st.begin(); it != st.end(); ++it) {
        result.push_back(*it);
    }
    return result;
}

vector<int> union2(int arr1[], int arr2[], int no1, int no2){
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<no1 && j<no2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size() == 0 || unionArr.back()!= arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0|| unionArr.back()!= arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<no1){
        if(unionArr.size() == 0 || unionArr.back()!=arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j<no2){
        if(unionArr.size() == 0 || unionArr.back()!=arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}



int main(){
    int no1, no2 = 0;
    cout<<"Enter number of elements in first array: ";
    cin>>no1;
    int arr1[no1]={0};
    cout<<"Enter arry elements: ";
    for(int i=0; i<no1; i++){
        cin>>arr1[i];
    }
    cout<<"Enter number of elements in second array: ";
    cin>>no2;
    int arr2[no2]={0};
    cout<<"Enter arry elements: ";
    for(int i=0; i<no2; i++){
        cin>>arr2[i];
    }
    vector<int> ret = union2(arr1, arr2, no1, no2);

    cout << "Union of two arrays is: ";
    for (int i = 0; i < (int)ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}