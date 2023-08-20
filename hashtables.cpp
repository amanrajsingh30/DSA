#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};
class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

public:
    void printTable(){
        for(int i=0;i<SIZE;i++){
            cout<<i<< ":"<<endl;
            if(dataMap[i]){
                Node* temp = dataMap[i];
                while(temp){
                    cout<< "    {"<<temp->key<< ", "<<temp->value<< "}"<<endl;
                    temp = temp->next;
                }
            }
        }
    }
    int hash(string key){
        int hash = 0;
        for(int i = 0;i<key.length();i++){
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue*23)%SIZE;

        }
        return hash;
    }
    void set(string key,int value){
        int index = hash(key);
        Node* newNode = new Node(key,value);
        if(dataMap[index] == nullptr){
            dataMap[index] = newNode;
        }else{
            Node* temp = dataMap[index];
            while(temp->next){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }
    int get(string key){
        int index = hash(key);
        Node* temp = dataMap[index];
        while(temp){
            if(temp->key == key)return temp->value;
            temp = temp->next;
        }
        return 0;
    }
    vector<string> keys(){
        vector<string> allKeys;
        for(int i=0;i<SIZE;i++){
            Node* temp = dataMap[i];
            while(temp){
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }




};
bool itemInCommon(vector<int> vect1,vector<int> vect2){
    unordered_map<int,bool> myMap;

    for(auto i: vect1){
        myMap.insert({i,true});
    }
    for(auto i: vect2){
        if(myMap[i]){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int> vect1 {1,2,3};
    vector<int> vect2 {2,4,6};
    cout<< itemInCommon(vect1, vect2);
    return 0;
}
