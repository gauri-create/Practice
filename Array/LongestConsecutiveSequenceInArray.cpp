#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int LongestCons (vector<int>arr, int n){
   if (n==0) return 0;
   int longest =1;
   unordered_set<int> st;
   for(int i=0; i<n; i++){
        st.insert(arr[i]);
   }

   for(auto it: st){
      if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1) != st.end()){
                x=x+1;
                cnt=cnt+1;
            } 
            longest = max(longest, cnt);
       }
   }
   return longest;
}

int main(){
   int no=0;
   cout<<"Enter size of array: ";
   cin>>no;
   vector<int> arr(no);
   cout<<"Enter array element: "<<endl;
   for(int i=0; i<no; i++){
       cin>>arr[i];
   }

   int ret = LongestCons(arr, no);
   cout<<"Longest consecutive of array is: "<<ret;
   

   return 0;
}