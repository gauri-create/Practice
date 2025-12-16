#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int findContentChildren(vector<int>& student, vector<int>& cookies){
        sort(student.begin(), student.end());
        sort(cookies.begin(), cookies.end());

        int studentIndex=0;
        int cookieIndex=0;

        while(studentIndex< student.size() && cookieIndex<cookies.size()){
            if(cookies[cookieIndex] >= student[studentIndex]) studentIndex++;
            cookieIndex++;
        }
        return studentIndex;
    }
};

int main(){
    Solution solver;
    vector<int>student={1, 2};
    vector<int>cookie = {1, 2, 3};
    int result = solver.findContentChildren(student, cookie);
    cout<<"Maximum number of content students: "<< result<< endl;
    return 0;
}