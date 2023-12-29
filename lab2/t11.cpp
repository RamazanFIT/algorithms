#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */ 
    if(p == 0){
        node->next = head;
        return node;
    }
    Node * result = head;
    for(int i = 0; i < p - 1; i++){
        head = head->next;
    }
    if(head->next == nullptr){
        head -> next = node;
        return result;
    } 
    node->next = head->next;
    head->next = node;
    return result;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if(p == 0){
        return head->next;
    }
    Node * result = head;
    for(int i = 0; i < p - 1; i++){
        head = head->next;
    }
    head->next = head->next->next;
    return result;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node * start = head;
    Node * node_1;
    for(int i = 0; i < p1; i++){
        head = head->next;
    }
    node_1 = head;
    head = remove(start, p1);
    return insert(head, node_1, p2);
    
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node * result = new Node();
    result->next = new Node();
    result->val = head->val;
    Node * prev = result;
    head = head->next;
    while(head->next != nullptr){
        Node * temp_node = new Node();
        temp_node->val = head->val;
        temp_node->next = prev;
        prev = temp_node;
        head = head->next;
    }
    return prev;
}
 
void print(Node* head){
    /* write your code here */
    while(head->next != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){

    Node * start = head;
    while(head -> next != nullptr){
        head = head->next;
    }
    Node * endd = head;
    head = start;
    for(int i = 0; i < x; i++){
        endd->val = head->val;
        endd->next = new Node();
        endd = endd->next;
        head = head->next;
    }
    return head;
    
}

Node* cyclic_right(Node* head, int x){
    if(x == 0){
        return head;
    }
    Node * start = head;
    int cnt = 0;
    while(head->next != nullptr){
        head = head->next;
        cnt++;
    }
    head = start;
    if(x == cnt){
        return head;
    }
    int size = 0;
    while(head->next != nullptr){
        head = head->next;
        size++;
    }
    head = start;
    for(int i = 0; i < size - x - 1; i++){
        head = head->next;
    }
    Node * ans = head->next;
    head->next = new Node();
    head = ans;
    while(head->next->next != nullptr){
        head = head->next;
    }
    head->next = start;

   
    return ans;


}


 

 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    Node* head = new Node();
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}