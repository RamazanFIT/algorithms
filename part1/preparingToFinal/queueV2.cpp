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
    }
};

struct Queue{
    // push(), pop(), front(), back() - O(1) 
    Node * head;
    Node * tail;
    int size = 0;
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void push(int value){
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
    
    int pop(){
        if(head == NULL) return NULL;
        if(head == tail){
            int toReturn = head->value;
            head = NULL;
            tail = head;
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

    int getSize() {return size;}

    int back(){
        return tail->value;
    } 
    int front(){
        return head->value;
    }
};

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    Queue q;
    q.push(12);
    // cout << q.pop() << " ";
    for(int i = 1; i < 100; i++){
        q.push(i);
    }
    q.pop();
    cout << q.front() << " " << q.back() << ENDL;
    // while(q.getSize() != 0){
    //     cout << q.pop() << " ";
    //     // cout << q.getSize() << " ";
    //     q.pop();

    // }
    // cout << q.getSize() << " ";
    // q.push(111);
    // cout << ENDL << q.pop() << " ";
    // cout << q.getSize() << " ";


    endd
}