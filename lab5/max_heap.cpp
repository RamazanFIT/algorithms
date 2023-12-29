#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

struct max_heap{
    vector<int> massive;

    int getParent(int index){
        return (index - 1) / 2;
    }

    int getLeftChild(int index){
        return index * 2 + 1;
    } 

    int getRightChild(int index){
        return index * 2 + 2;
    }

    void heapifyDown(int index){
        int pos_left = getLeftChild(index);
        int pos_right = getRightChild(index);
        int largest = index;
        if(pos_left < getSize() and massive[pos_left] > massive[largest]){
            largest = pos_left;
        }
        if(pos_right < getSize() and massive[pos_right] > massive[largest]){
            largest = pos_right;
        }
        if(largest == index) return;
        swap(massive[largest], massive[index]);
        heapifyDown(largest);
    }

    void heapifyUp(int index){
        if(index == 0) return;
        int father = getParent(index);
        if(massive[father] < massive[index]){
            swap(massive[father], massive[index]);
            heapifyUp(father);
        }
    }

    void push(int element){
        massive.push_back(element);
        int last_index = getSize() - 1;
        heapifyUp(last_index);
    }

    void pop(){
        if(getSize() == 0) return;
        
        swap(massive[0], massive[getSize() - 1]);
        massive.pop_back();
        heapifyDown(0);
    }

    int top(){
        if(getSize() == 0) return NULL;
        return massive[0];
    }

    int getSize(){
        return massive.size();
    }
};

int current_size;
vector<int> massive;

int getSize(){
    return massive.size();
}



int top(){
    if(getSize() == 0) return NULL;
    return massive[0];
}

int getParent(int index){
        return (index - 1) / 2;
    }

int getLeftChild(int index){
    return index * 2 + 1;
} 

int getRightChild(int index){
    return index * 2 + 2;
}

void heapifyDown(int index){
    int pos_left = getLeftChild(index);
    int pos_right = getRightChild(index);
    int largest = index;
    if(pos_left < current_size and massive[pos_left] > massive[largest]){
        largest = pos_left;
    }
    if(pos_right < current_size and massive[pos_right] > massive[largest]){
        largest = pos_right;
    }
    if(largest == index) return;
    swap(massive[largest], massive[index]);
    heapifyDown(largest);
}
void pop(){
    if(current_size == 0) return;
    
    swap(massive[0], massive[current_size - 1]);
    current_size--;
    // massive.pop_back();
    heapifyDown(0);
}
void heapifyUp(int index){
    if(index == 0) return;
    int father = getParent(index);
    if(massive[father] < massive[index]){
        swap(massive[father], massive[index]);
        heapifyUp(father);
    }
}

void heap_sort(){
    current_size = massive.size();
    for(int i = massive.size() - 1; i >= 0; i--){
        heapifyDown(i);
    } 
    for(int i = 0; i < massive.size(); i++){
        pop();
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    max_heap pq;

    // pq.push(1);
    // pq.push(2);
    // cout << pq.top() << ENDL;
    // pq.pop();
    // cout << pq.top() << ENDL;

    pq.push(-1);
    pq.push(-2);
    cout << pq.top() << ENDL;
    pq.pop();
    cout << pq.top() << ENDL;
    
    
    // for(int i = 100; i >= 1; i--){
    //     massive.push_back(i);
    // }
    // for(int i = 0; i < massive.size(); i++){
    //     cout << massive[i] << " ";
    // } cout << ENDL;
    // heap_sort();
    // for(int i = 0; i < massive.size(); i++){
    //     cout << massive[i] << " ";
    // } cout << ENDL;

    endd
}