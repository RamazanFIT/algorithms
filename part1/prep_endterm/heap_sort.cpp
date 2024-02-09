#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void heapify_down(vector<int> & massive, int i, int n){ // log n
    int maximal_pos = i;
    int left_child = (i * 2) + 1;
    int right_child = (i * 2) + 2;
    if(left_child < n and massive[left_child] > massive[maximal_pos]){
        maximal_pos = left_child;
    }
    if(right_child < n and massive[right_child] > massive[maximal_pos]){
        maximal_pos = right_child;
    }
//     0
// 0       0
    if(maximal_pos == i) return;
    swap(massive[maximal_pos], massive[i]);
    heapify_down(massive, maximal_pos, n);
}

void build_heap(vector<int> & massive){ // O(N) 
    int first_parent = ((massive.size() - 1) - 1) / 2; // size / 2 - 1 ->first parent
    for(int i = first_parent; i >= 0; i--){
        heapify_down(massive, i, massive.size());
    } // вставка на правильное место вершины 
}

void my_heap_sort(vector<int> & massive){
    build_heap(massive);
    for(int i = 0; i < massive.size() - 1; i++){
        swap(massive[0], massive[massive.size() - 1 - i]);
        heapify_down(massive, 0, massive.size() - 1 - i);
    }
    // best worth avarage - O(n * log(n))
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    // max_heap heap;
    vector<int> massive;
    
    for(int i = 0; i < n; i++){
        int el;cin>>el;
        // heap.push(el);
        massive.pb(el);
    }
    // for(int i = 0; i < n; i++){
    //     cout << heap.top() << " ";
    //     heap.pop();
    // }
    // build_heap(massive);
    my_heap_sort(massive);
    for(int i = 0; i < n; i++){
        cout << massive[i] << " ";
    }


    endd
}