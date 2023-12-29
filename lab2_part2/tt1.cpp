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
        next = NULL;
        prev = NULL;
        value = "not_allowed";
    }
};

struct DoubleLinkedList{

    Node * left = new Node();
    Node * right;

    DoubleLinkedList(){
        // left = new Node();
        // right = new Node();
        // left->prev = new Node();
        // right->next = new Node();
        // right->prev = left;
        // left->next = right;


        right = left;
        // left->next = new Node();
        // left->prev = new Node();
    }
    string add_front(string a){
        // left->value = a;
        // left = left->prev;
        // left->prev = new Node();
        // return "ok";
        left->prev = new Node();
        left->prev->value = a;
        left->prev->next = left;
        left = left->prev;
        if(right->value == "not_allowed"){
            right = left;
        }
        return "ok";

    }

    string add_back(string a){
        // right->value = a;
        // right = right->next;
        // right->next = new Node();
        // return "ok";

        left->next = new Node();
        left->next->value = a;
        left->next->prev = left;
        left = left->next;
        if(left->value == "not_allowed"){
            left = right;
        }
        return "ok";
    }

    string erase_front(){
        // if(left->next->value == "not_allowed"){
        //     return "error";
        // }
        // left = left->next;
        // left->prev = new Node();
        // return "ok";


        if(left->next == NULL){
            return "error";
        } else{
            left = left->next;
            left->prev = NULL;

            return "ok";
        }
    }

    string erase_back(){
        // if(right->prev->value == "not_allowed"){
        //     return "error";
        // }
        // right = right->prev;
        // right->next = new Node();
        // return "ok";



        if(right->prev == NULL){
            return "error";
        } else{
            right = right->prev;
            right->next = NULL;
            return "ok";
        }
    }

    string front(){
        // if(left->next->value == "not_allowed"){
        //     return "error";
        // }
        // return left->next->value;

        if(left == NULL){
            return "error";
        }
        return left->value;
    }

    string back(){
        // if(right->prev->value == "not_allowed"){
        //     return "error";
        // }
        // return right->prev->value;

        if(right == NULL){
            return "error";
        }
        return right->value;
    }

    string clear(){
        // left = new Node();
        // right = new Node();
        // left->prev = new Node();
        // right->next = new Node();
        // right->prev = left;
        // left->next = right;
        // return "ok";

        left = new Node();
        right = left;
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
            node.add_front(value);
            cout << "ok" << ENDL;
        } else if(a == "add_back"){
            cin>>value;
            node.add_back(value);
            cout << "ok" << ENDL;
        } else if(a == "erase_front"){
            node.erase_front();
            cout << "ok" << ENDL;
        } else if(a == "erase_back"){
            node.erase_back();
            cout << "ok" << ENDL;
        } else if(a == "front"){
            cout << node.front() << ENDL;
        } else if(a == "back"){
            cout << node.back() << ENDL;
        } else if(a == "clear"){
            node.clear();
            cout << "ok" << ENDL;
        } else if(a == "exit"){
            cout << "goodbye" << ENDL;
            return 0;
        }
    }
    


    endd
}