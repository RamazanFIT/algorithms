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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    max_heap pq;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    while(pq.getSize() > 1){
        int x, y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        if(x != y){
            pq.push(x - y);
        }
    }
    if(pq.getSize() == 1)
    cout << pq.top();
    else cout << 0;
    


    endd
}