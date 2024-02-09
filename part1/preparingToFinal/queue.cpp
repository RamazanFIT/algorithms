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
    Node(int value, Node * prev){
        this->value = value;
        this->prev = prev;
    }
};

struct Queue{
    Node * head;
    Node * tail;
    int size = 0;
    Queue(){
        head = new Node();
        tail = new Node();
        tail->prev = head;
    }

    void push(int value){
        if(tail->prev == head){
            head = tail;
            head->value = value;
            tail->next = new Node();
            tail = tail->next;
        } else{
            tail->value = value;
            tail->next = new Node(NULL, tail);
            tail = tail->next;
        }
        size++;
    }
    
    int pop(){
        if(head->next == NULL or size == 0) return NULL;
        int toReturn = head->value;
        if(head->next == tail){
            head = new Node();
            tail = new Node();
            tail->prev = head;
        } else{
            head = head->next;
            head->prev = NULL;
        }
        
        size--;
        return toReturn;
    }

    int getSize() {return size;}
};

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    Queue q;
    q.push(12);
    cout << q.pop() << " ";
    for(int i = 1; i < 100; i++){
        q.push(i);
    }
    while(q.getSize() != 0){
        cout << q.pop() << " ";
    }
    cout << q.getSize() << " ";
    q.push(111);
    cout << ENDL << q.pop() << "";
    cout << q.getSize() << " ";

    endd
}