#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum1(vector<int> nums, int n, int target){
    set<vector<int>>st;
    for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n;  k++){
                for(int l=k+1; l<n; l++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum==target){
                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                         sort(temp.begin(), temp.end());
                         st.insert(temp);
                    }
                }
            }
       }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum2(vector<int> nums, int n, int target){
    set<vector<int>>st;
    for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
        set<long long> hashset;
            for(int k=j+1; k<n;  k++){
                long long sum;
                sum = nums[i]+nums[j]+nums[k];
                int fourth = target-(sum);
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
       }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum3(vector<int> nums, int n, int target){
   vector<vector<int>> ans;
   sort(nums.begin(), nums.end());
   for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j!= i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=0;
                sum += nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
                else if(sum<target)k++;
                else l--;
            }    
        }
   }
   return ans;
}

int main(){
    int no=0;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>> arr[i];
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    // vector<vector<int>> ret= fourSum1(arr, no, target);
    // vector<vector<int>> ret= fourSum2(arr, no, target);
    vector<vector<int>> ret= fourSum3(arr, no, target);

    for(int i=0; i<no; i++){
        for(int j=0; j<4; j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
}