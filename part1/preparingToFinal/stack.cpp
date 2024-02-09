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
    Node * next;
    Node * prev;
    int value;
    Node(){
        value = NULL;
        next = NULL;
        prev = NULL;
    }
    Node(int value, Node * prev){
        this->value = value;
        this->prev = prev;
    }
};


struct Stack{
    // LIFO 
    // push() - O(1) 
    // pop() - O(1) 
    // top() - O(1) 
    // empty() - O(1) 
    Node * head;
    int size = 0;
    Stack(){
        head = new Node();
    }
    void push(int value){
        size++;
        head->next = new Node(value, head);
        head = head->next;
    }
    int pop(){
        if(size == 0) return NULL;
        size--;
        int toReturn = head->value;
        if(size == 0) head = new Node();
        else head = head->prev;
        return toReturn;
    }

    int getSize(){
        return size;
    }
};


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    Stack st;
    // st.push(1);
    // cout << st.pop() << ENDL;
    // st.push(2);
    // st.push(3);
    // while(st.getSize() != 0){
    //     cout << st.pop() << " ";
    // }
    for(int i = 1; i < 100; i++){
        st.push(i);
    }
    while(st.getSize() != 0){
        cout << st.pop() << " ";
    }
    



    endd
}