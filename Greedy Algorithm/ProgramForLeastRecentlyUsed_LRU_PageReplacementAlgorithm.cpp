#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class LRUCache {
private: 
  int cap;
  list<pair<int, int>>dll;
  unordered_map<int, list<pair<int, int>>::iterator>mp;

  public:

  LRUCache(int capacity) {
     cap=capacity;
  }

  int get(int key_) {
     auto it = mp.find(key_);
     if(it==mp.end()) return -1;
     dll.splice(dll.begin(), dll, it->second);
     return it->second->second;
  }

  void put(int key_, int value) {
      auto it = mp.find(key_);
      if(it != mp.end()){
        it->second->second=value;
        dll.splice(dll.begin(), dll, it->second);
      }
      else{
        if(dll.size()==cap){
            mp.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({key_, value});
        mp[key_]=dll.begin();
    }
  }
};

int main(){
    LRUCache* obj= nullptr;
    vector<string> command = {"LRUCache", "put", "put", "get", "put", "get", "put", "get"};
    vector<vector<int>> input={{1}, {1,1}, {2,2}, {1},{3,3}, {2}, {4,4}, {3}};
    
    for(int i=0; i<command.size(); i++){
        if(command[i] == "LRUCache"){
            obj = new LRUCache(input[i][0]);
            cout<<"null ";
        }
        else if(command[i] == "put"){
            obj->put(input[i][0], input[i][1]);
            cout<<"null ";
        }
        else if(command[i]== "get"){
            cout<<obj->get(input[i][0])<<" ";
        }
    }
    delete obj;
    return 0;
}