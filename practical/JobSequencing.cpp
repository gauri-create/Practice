#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    char id;
    int deadlines;
    int profit;
};

class Solution{
    public:
    void jobSequence(vector<Job>nums, int n){
        sort(nums.begin(), nums.end(), [](Job &a, Job &b){return a.profit>b.profit;});
        int maxDeadline=0;
        for(auto &job : nums){
            if(job.deadlines>maxDeadline)
                maxDeadline=job.deadlines;
        }
        vector<char>schedule(maxDeadline+1, '-');
        int totalProfit=0;

        for(auto &job: nums){
            for(int t=job.deadlines; t>0; t--){
                if(schedule[t]=='-'){
                    schedule[t]=job.id;
                    totalProfit+=job.profit;
                    break;
                }
            }
        }

    }
};

int main(){
    Solution obj;
    vector<Job> nums={
        {'a', 2,100},
        {'b',1,19},
        {'c',2,27},
        {'d',1,25},
        {'e',3,15}
    };
    int n=nums.size();
    obj.jobSequence(nums,n);
    return 0;
}
