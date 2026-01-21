#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Brutefore
vector<vector<int>> Triplet1(vector<int> &num, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n;j++ ){
           for(int k=j+1; k<n; k++){
               if(num[i]+num[j]+num[k]==0){
              vector<int>temp={num[i], num[j], num[k]};
              sort(temp.begin(), temp.end());
              st.insert(temp);
              }
             }
         }
     }
     vector<vector<int>> ans(st.begin(), st.end());
     return ans;

}

//Better
vector<vector<int>> Triplet2(vector<int> num, int n){
   set<vector<int>> st;
   for(int i=0; i<n; i++){
       set<int>hashset;
       for(int j=i+1; j<n;j++){
            int third= -(num[i]+num[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
       }  
   }
   vector<vector<int>> ans(st.begin(), st.end());
   return ans;
}

// //optimal
vector<vector<int>>Triplet3(vector<int> num, int n){
     vector<vector<int>>ans;

     sort(num.begin(), num.end());
     for(int i=0; i<n; i++){
        if(i>0 && num[i]==num[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=num[i]+ num[j]+ num[k];
            if(sum<0){
             j++;
            }
            else if(sum>0){
              k--;
            }
            else {
                 vector<int>temp={num[i], num[j], num[k]};
                 ans.push_back(temp);
                 j++;
                 k--;
                 while(j<k && num[j]==num[j-1]) j++;
                 while(j<k && num[k]==num[k-1]) k--;
            }
        }
      
    }
    return ans;
}

int main(){
    int no;
    cout<<"Enter size of array: ";
    cin>>no;
    cout<<"Enter array elements: "<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    // vector<vector<int>> ret= Triplet1(arr, no);
    vector<vector<int>> ret= Triplet2(arr, no);
    // vector<vector<int>> ret= Triplet3(arr, no);

    for(int i=0; i<ret.size(); i++){
       for(int j=0; j<3; j++){
            cout<<ret[i][j]<<" ";
       }
       cout<<endl;
    }

}
