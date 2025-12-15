#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
    vector<int>heap;

    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

    void heapifyDown(int i){
        int smallest=i;
        int l=left(i);
        int r=right(i);

        if(l<heap.size() && heap[l]<heap[smallest]) smallest=l;
        if(r<heap.size() && heap[r]<heap[smallest]) smallest=r;

        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i){
        while(i != 0 && heap[parent(i)]>heap[i]){
            swap(heap[i], heap[parent(i)]);
            i=parent(i);
        }
    }

    public:

        void initializeHeap(){
            heap.clear();
        }

        void insert(int key){
            heap.push_back(key);
            heapifyUp(heap.size()-1);
        }

        void changeKey(int index, int new_val){
            if(index<0 || index >= heap.size()) return;
            int old=heap[index];
            heap[index]=new_val;

            if(new_val < old) heapifyUp(index);
            else heapifyDown(index);
        }

        void extractMin(){
            if(heap.empty()) return;
            if(heap.size()==1){
                heap.pop_back();
                return;
            }
            heap[0]=heap.back();
            heap.pop_back();
            heapifyDown(0);
        }

        bool isEmpty(){
            return heap.empty();
        }

        int getMin(){
            if(heap.empty()) return INT_MAX;
            return heap[0];
        }

        int heapSize(){
            return heap.size();
        }
};

int main(){
    Solution obj;
    vector<string> operations={"initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey", "getMin"};
    vector<vector<int>>nums={{4}, {1}, {10}, {0, 16}};
    for(int i=0; i<operations.size(); i++){
        if(operations[i]=="initializeheap") {
            obj.initializeHeap();
            cout<<"null"<<" ";
        }
        else if(operations[i]=="insert") {
            obj.insert(nums[i][0]);
            cout<<"null"<<" ";
        }
        else if(operations[i]=="getMin"){
            cout<<obj.getMin()<<" "; 
        }
        else if(operations[i]=="heapSize"){
            cout<<obj.heapSize()<<" ";
        }
        else  if(operations[i]=="isEmpty"){
            cout<<(obj.isEmpty()? "true " : "false");
        }
        else if(operations[i]=="extractMin"){
            obj.extractMin();
            cout<<"null ";
        }
        else if(operations[i]=="changeKey"){
            obj.changeKey(nums[i][0], nums[i][1]);
            cout<<"null ";
        }
    }
    return 0;
}