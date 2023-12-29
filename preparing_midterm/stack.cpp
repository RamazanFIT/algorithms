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


struct own_stack{
    Node * head = NULL;
    int size_stack = 0;
    void push(int x){
        if(head == NULL){
            head = new Node(x);

        } else{
            head->next = new Node(x);
            head->next->prev = head;
            head = head->next;
          
        }
        size_stack++;
    }

    int top(){
        if(head == NULL){
            return NULL;
        } else{
            return head->value;
        }
    }

    void pop(){
        if(head == NULL) return;
        
        if(head->prev == NULL){
            head = NULL;
        } else{
            head = head->prev;
            head->next = NULL;
        }
        size_stack = max(0, size_stack - 1);
    }

    bool empty(){
        return size() == 0;
    }

    int size(){
        return size_stack;
    }
     
};



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    own_stack st;
    st.push(1);
    cout << st.top() << ENDL;
    st.pop();
    st.push(12);
    st.push(13);
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);st.push(12);
    st.push(13);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    endd
}