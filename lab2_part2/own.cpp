#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


struct Node{
    Node * next;
    Node * prev;
    string value;
    Node(){
        value = "";
        next = NULL;
        prev = NULL;
    }
   
};

struct DoubleLinkedList{

    Node * head;
    Node * tail;
    int size;
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    
    string add_front(string a){
        if(head == NULL){
            head = new Node();
            head->value = a;
            tail = head;
        } else{
            head->prev = new Node();
            head->prev->value = a;
            head->prev->next = head;
            head = head->prev;
        }
        size++;
        return "ok";
    }   

    string add_back(string a){
        if(tail == NULL){
            head = new Node();
            head->value = a;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
        } else{
            tail->next = new Node();
            tail->next->value = a;
            tail->next->prev = tail;
            tail = tail->next;
        }
        size++;
        return "ok";
    }

    string erase_front(){
        if(size <= 0){
            return "error";
        }
        string value_to_give = head->value;
        if(size == 1){
            this->clear();
            return value_to_give;
        }
        head = head->next;
        head->prev = NULL;
        size--;
        return value_to_give;
    }

    string erase_back(){
        if(size <= 0){
            return "error";
        }
        string value_to_give = tail->value;
        if(size == 1){
            this->clear();
            return value_to_give;
        }
        tail = tail->prev;
        tail->next = NULL;
        size--;
        return value_to_give;
    }

    string front(){
        if(size <= 0){
            return "error";
        }
        return head->value;
    }

    string back(){
        if(size <= 0){
            return "error";
        }
        return tail->value;
    }

    string clear(){
        head = NULL;
        tail = NULL;
        size = 0;
        return "ok";
    }



};





signed main(){

    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);
    DoubleLinkedList node;
    while(true){
        string a;
        cin>>a;
        string value;
        
        if(a == "add_front"){
            cin>>value;
            cout << node.add_front(value);
            cout << ENDL;
            
        } else if(a == "add_back"){
            cin>>value;
            cout << node.add_back(value);
            cout << ENDL;
        } else if(a == "erase_front"){
            cout << node.erase_front();
            cout << ENDL;
        } else if(a == "erase_back"){
            cout << node.erase_back();
            cout << ENDL;
        } else if(a == "front"){
            cout << node.front() << ENDL;
        } else if(a == "back"){
            cout << node.back() << ENDL;
        } else if(a == "clear"){
            cout << node.clear();
            cout << ENDL;
        } else if(a == "exit"){
            cout << "goodbye" << ENDL;
            return 0;
        }
    }
    


    endd
}