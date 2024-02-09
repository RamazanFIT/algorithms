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
    int value;
    Node * prev;
    Node * next;
    Node(){
        value = NULL;
        prev = NULL;
        next = NULL;
    }
    Node(int value){
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

struct own_queue{
    Node * head = NULL; 
    Node * tail = NULL;
    int size = 0;
    
    void push(int x){
        if(head == NULL){
            head = new Node(x);
            tail = head;
        } else{
            tail->prev = new Node(x);
            tail->prev->next = tail;
            tail = tail->prev;
        }
        size++;
    }

    int top(){
        if(head != NULL){
            return head->value;
        }
        return NULL;
    }

    int back(){
        if(tail != NULL){
            return tail->value;
        } return NULL;
    }

    void pop(){
        if(head == NULL) return;

        if(head == tail){
            head = NULL;
            tail = NULL;
        } else{
            head = head->prev;
            head->next = NULL;
        }
        size--;
    }

    int getSize(){
        return size;

    }
    bool empty(){
        return size == 0;
    }
    

};


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    own_queue q;
    q.push(1);
    cout << q.back() << " " << q.top() << ENDL;
    q.push(2);
    cout << q.back() << " " << q.top() << ENDL;
    q.push(3);
    q.push(4);
     cout << q.back() << " " << q.top() << ENDL;
    q.pop();
     cout << q.back() << " " << q.top() << ENDL;
    q.pop();
     cout << q.back() << " " << q.top() << ENDL;
    q.pop();
     cout << q.back() << " " << q.top() << ENDL;
    q.pop();
     cout << q.back() << " " << q.top() << ENDL;
    q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);q.push(3);
    q.push(4);
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    endd
}