#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;
class Dictionary{
    static const int TABLESIZE =10;

    list<pair<string,string>>* table;
  
    int hashfunction(string key){
        int hash =0;
        for(int i = 0; i<key.length();i++){
            hash = (hash + key[i])%TABLESIZE;
        }
        return hash;
    }
    public:
    Dictionary(){
        table = new list<pair<string, string>>[TABLESIZE];
    }
    void inserthash(string key, string value){
        int index = hashfunction(key);
        for(auto&  it: table[index]){
            if(it.first == key){
                it.second = value;
                return;
            }
            table[index].push_back(make_pair(key,value));
        }
        cout<<"inserted.";
        return;
    }
    void findString(string key){
        int index = hashfunction(key);
        for(auto& it:table[index]){
            if(it.first == key){
                cout<<"key found."<<endl;
                cout<<"Key: "<<it.first<<" \nvalue: "<<it.second<<endl; 
            }
            else{
                cout<<"Key nnot found"<<endl;
            }
        }
    }
    void deletekey(string key){
        int index = hashfunction(key);
        auto& bucket = table[index];
        for(auto it = bucket.begin(); it!= bucket.end();++it){
            if(it->first == key){
                bucket.erase(it);
                cout<<key<<"deleted"<<endl;
                return;
            }
            cout<<"Not found";
            return ;
        }
       }
    void display(){
        for(int i =0;i<TABLESIZE;i++){
            if(!table[i].empty()){
                for(auto& it:table[i]){
                    cout<<it.first<<": "<<it.second<<endl;
                }
            }
        }
    }
};
int main(){
    Dictionary dict;
    dict.inserthash("1","A");
    dict.inserthash("2","B");
    dict.inserthash("3","C");
    dict.inserthash("4","D");
    dict.inserthash("5","E");
    dict.display();
    dict.inserthash("1","z");
    dict.deletekey("3");
    dict.display();
    dict.findString("4");
    return 0;
}