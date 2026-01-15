#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0; i<word.size(); i++){
             if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string word){
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntEndWith;
    }
    int countWordsStartingWith(string word){
        Node* node=root;
        for(int i=0;i<word.size(); i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntPrefix;
    }
    void erase(string word){
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return ;
            }
        }
        node->deleteEnd();
    }
};

int main(){
    vector<string> commands={"Trie", "insert", "countWordsEqualTo", "insert", "countWordsStartingWith", "erase", "countWordsStartingWith",};
    vector<string> input={{},"apple", "apple", "app", "app", "apple", "app"};
    Trie obj;
    for(int i=0; i<=commands.size(); i++){
        if(commands[i]=="Trie"){
            Trie();
            cout<<"null"<<endl;
        }
        else if(commands[i]=="insert"){
            obj.insert(input[i]);
            cout<<"null"<<endl;
        }
        else if(commands[i]=="countWordsEqualTo"){
            int ans=obj.countWordsEqualTo(input[i]);
            cout<<ans<<endl;
        }
        else if(commands[i]=="countWordsStartingWith"){
            int ans=obj.countWordsStartingWith(input[i]);
            cout<<ans<<endl;
        }
        else if(commands[i]=="erase"){
            obj.erase(input[i]);
            cout<<"null"<<endl;
        }
    }
    return 0;
}