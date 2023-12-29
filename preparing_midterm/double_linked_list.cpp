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

struct linked_list{
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
    
    int getSize(){
        return size;

    }
    bool empty(){
        return size == 0;
    }
    
    void insertAfter(Node * x, int data){
        Node * cur = tail;
        while(cur != NULL){
            if(x == cur){
                if(cur->next == NULL){
                    cur->next = new Node(data);
                    size++;
                    return;
                } else{
                    Node * tmp = cur->next;
                    cur->next = new Node(data);
                    cur->next->next = tmp;
                    tmp->prev = cur->next; 
                    size++;
                    return;
                }
            }
            cur = cur->next;
        }
    }

    void eraseAfter(Node * x){
        Node * cur = tail;
        while(cur != NULL){
            if(x == cur){
                if(cur->next == NULL){                  
                    return;
                } else if(cur->next->next == NULL){
                    cur->next = NULL;
                    size--;
                    return;
                } else{
                     cur->next = cur->next->next;
                    cur->next->prev = cur;
                    size--;
                    return;
                }
                
                
                
                
            }
            cur = cur->next;
        }
        
    }
    

};


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    linked_list myList;

    // Тест 1: Добавление элементов и проверка методов push_back, top, back
    // myList.push_back(1);
    // assert(myList.top() == 1); // Ожидаем, что верхний элемент - 1
    // assert(myList.back() == 1); // Ожидаем, что последний элемент - 1

    // myList.push_back(2);
    // assert(myList.top() == 1); // Ожидаем, что верхний элемент все равно 1
    // assert(myList.back() == 2); // Ожидаем, что последний элемент - 2

    // // Тест 2: Удаление элементов и проверка методов pop_back, getSize, empty
    // myList.pop_back();
    // assert(myList.top() == 1); // Ожидаем, что верхний элемент - 1
    // assert(myList.back() == 1); // Ожидаем, что последний элемент опять 1
    // assert(myList.getSize() == 1); // Ожидаем, что размер равен 1
    // assert(!myList.empty()); // Ожидаем, что список не пуст

    // myList.pop_back();
    // assert(myList.getSize() == 0); // Ожидаем, что размер равен 0
    // assert(myList.empty()); // Ожидаем, что список пуст

     myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // Тест 1: Проверка метода insertAfter
    Node* nodeToInsertAfter = myList.head; // Вставляем после первого элемента (значение 1)
    myList.insertAfter(nodeToInsertAfter, 4);
    assert(myList.back() == 3); // Ожидаем, что последний элемент всё еще 3
    assert(myList.head->next->value == 4); // Ожидаем, что значение после 1 - 4
    cout << nodeToInsertAfter->value << ENDL;
    // Тест 2: Проверка метода eraseAfter
    myList.eraseAfter(nodeToInsertAfter); // Удаляем элемент со значением 4
    assert(myList.back() == 3); // Ожидаем, что последний элемент - 3
    assert(myList.head->next == nullptr); // Ожидаем, что элемента со значением 4 больше нет

    // Тест 3: Попробуем удалить элемент после последнего узла
    Node* lastNode = myList.tail; // Удаление элемента после последнего узла не должно вызывать ошибок
    myList.eraseAfter(lastNode);

   
    cout << myList.getSize() << ENDL;

    cout << "Все тесты пройдены успешно." << ENDL;
    
}