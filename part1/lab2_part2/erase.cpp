#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

struct Node{
    Node * next;
    Node * prev;
    char value;
    Node(){
        value = '-';
        next = NULL;
        prev = NULL;
    }
   
};

struct DoubleLinkedList{
public:
    Node * head;
    Node * tail;
    int size;
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    
    string add_front(char a){
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

    string add_back(char a){
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

    char erase_front(){
        if(size <= 0){
            return '-';
        }
        char value_to_give = head->value;
        if(size == 1){
            this->clear();
            return value_to_give;
        }
        head = head->next;
        head->prev = NULL;
        size--;
        return value_to_give;
    }

    char erase_back(){
        if(this->size <= 0){
            return '-';
        }
        char value_to_give = this->tail->value;
        if(this->size == 1){
            this->clear();
            return value_to_give;
        }
        this->tail = tail->prev;
        this->tail->next = NULL;
        this->size--;
        return value_to_give;
    }

    char front(){
        if(this->size <= 0){
            return '-';
        }
        return this->head->value;
    }

    char back(){
        if(size <= 0){
            return '-';
        }
        return tail->value;
    }

    void clear(){
        head = NULL;
        tail = NULL;
        size = 0;
        
    }

    int get_size(){
        return this->size;
    }
    
    void erase(char a){
        Node * to_delete = loop(a, this->head);
        // cout << to_delete->value << " ";
        if(to_delete == NULL) return;
        if(size <= 0){
            return;
        } else if(size == 1){
            this->clear();
        }  else
            if(to_delete->next == NULL){
               
                this->erase_back();
            } else if(to_delete->prev == NULL){
                
                this->erase_front();
            }
            else{
            to_delete->prev->next = to_delete->next;
            to_delete->next->prev = to_delete->prev;
            delete to_delete;
            size--;
            }
    }

    Node * loop(char a, Node * tmp){
        if(tmp == NULL) return NULL;
        if(tmp->value == a){
            return tmp;
        } else{
            return loop(a, tmp->next);
        }
    }


};

void solve(){
    int n;
    cin>>n;
    DoubleLinkedList list1;
    set<char> check;
    set<char> deleted;
    for(int i = 0; i < n; i++){
        char a;
        cin>>a;
        if((check.size() != 0) and (check.find(a) != check.end())){
            if(deleted.find(a) == deleted.end()){

                list1.erase(a);
                deleted.insert(a);
            }
        } else{
            check.insert(a);
            list1.add_back(a);
        }
        check.insert(a);
        if(list1.get_size() == 0){
            cout << "-1" << " ";
        } else{
            if(list1.front() != '-'){
                cout << list1.front() << " ";
            } else{
                cout << "-1" << " ";
            }
        }

    }
    cout << ENDL;
}


signed main(){
    
    // goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}