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

struct own_deque{
    Node * head = NULL; 
    Node * tail = NULL;
    int size = 0;
    // tail .. . head
    void push_back(int x){
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

    void push_front(int x){
        if(head == NULL){
            head = new Node(x);
            tail = head;
        } else{
            head->next = new Node(x);
            head->next->prev = head;
            head = head->next; 
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

    void pop_front(){
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

    void pop_back(){
        if(tail == NULL) return;
        
        if(head == tail){
            head = NULL;
            tail = NULL;
        } else{
            tail = tail->next;
            tail->prev = NULL;
            
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

    
    own_deque dq;
    dq.push_back(1);
    dq.push_back(2);
    cout << dq.back() << "  " << dq.top() << ENDL; 
    dq.push_back(3);
    dq.push_back(4);
    cout << dq.back() << "  " << dq.top() << ENDL;
    dq.push_front(100);
        cout << dq.back() << "  " << dq.top() << ENDL;
    dq.pop_front();
        cout << dq.back() << "  " << dq.top() << ENDL;
         dq.pop_front();
        cout << dq.back() << "  " << dq.top() << ENDL;
        dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);dq.push_back(12);
        dq.push_front(13);

    while(!dq.empty()){
        cout << dq.top() << " " << dq.back() << ENDL;
        dq.pop_back();
        dq.pop_front();
    }
}