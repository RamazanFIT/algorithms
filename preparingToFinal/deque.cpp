#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

struct Node{
    Node * prev;
    Node * next;
    int value;
    Node(){
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int value){
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

struct Deque{
    Node * head;
    Node * tail;
    int size = 0;
    Deque(){
        head = NULL;
        tail = head;
    }
    
    void push_back(int value){
        if(head == NULL){
            head = new Node(value);
            tail = head;
        } else{
            tail->next = new Node(value);
            tail->next->prev = tail;
            tail = tail->next;
        }
        size++;
    }

    void push_front(int value){
        if(head == NULL){
            head = new Node(value);
            tail = head;
        } else{
            head->prev = new Node(value);
            head->prev->next = head;
            head = head->prev;
        }
        size++;
    }

    int pop_back(){
        if(tail == NULL) return NULL;
        if(tail == head){
            int toReturn = head->value;
            head = NULL;
            tail = NULL;
            size--;

            return toReturn;
        } else{
            int toReturn = tail->value;
            tail = tail->prev;
            tail->next = NULL;
            size--;

            return toReturn;
        }

    }

    int pop_front(){
        if(tail == NULL) return NULL;
        if(tail == head){
            int toReturn = head->value;
            head = NULL;
            tail = NULL;
            size--;
            return toReturn;
        } else{
            int toReturn = head->value;
            head = head->next;
            head->prev = NULL;
            size--;
            return toReturn;
        }
        
    }

    void insert(int pos, int value){
        if(size == 0){
            push_back(value);
            return;
        }
        Node * cur = head;
        for(int i = 0; i < pos; i++){
            if(cur->next == NULL) break;
            cur = cur->next;
        }
        Node * save = cur->next;
        if(save == NULL){
            cur->next = new Node(value);
        } else{
            cur->next = new Node(value);
            cur->next->next = save;
        }
    }   

    void erase(int pos){
        if(size == 0) return;
        Node * cur = head;
        for(int i = 0; i < pos; i++){
            if(cur->next == NULL) break;
            cur = cur->next;
        }
        if(cur->prev == NULL){
            cur = cur->next;
            cur->prev = NULL;
        } else if(cur->next == NULL){
            cur = cur->prev;
            cur->next = NULL;
        } else{
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        size--;
    }

    int getSize(){
        return size;
    }
};

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    Deque dq;
    // dq.push_front(222);
    // dq.push_front(111);
    // cout << dq.pop_front();
    // cout << dq.pop_back();
    for(int i = 1; i < 16; i++){
        dq.push_back(i);
        dq.push_front(i);
    }
    while(dq.getSize() != 0){
        cout << dq.pop_front() << " ";
    }


    endd
}