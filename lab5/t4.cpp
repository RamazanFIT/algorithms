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
    int m;
    cin >> m;
    max_heap pq;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(-a);
    }
    int operation = 0;
    while(pq.getSize() > 1){
        if(-pq.top() >= m) break;
        
        int d1_least = -pq.top();
        pq.pop();
        int d2_least = -pq.top();
        pq.pop();
        int d_new = d1_least + 2 * d2_least;
        pq.push(-d_new);

        operation++;
    }
    if(pq.getSize() <= 0 or -pq.top() < m){
        cout << -1 << ENDL;
    } else{
        cout << operation << ENDL;
    }
    


    endd
}