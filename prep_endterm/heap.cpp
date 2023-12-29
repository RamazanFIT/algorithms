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

struct max_heap{
    vector<int> massive;

    int get_left_child(int i){
        return 2 * i + 1;
    }

    int get_right_child(int i){
        return 2 * i + 2;
    }

    int get_father(int i){
        return (i - 1) / 2;
    }

    void heapify_up(int i){
        if(i == 0) return;
        int parent = get_father(i);
        if(massive[parent] < massive[i]){
            swap(massive[parent], massive[i]);
            heapify_up(parent);
        }
        // log(n)

    }

    void heapify_down(int i){
        int maximal_pos = i;
        int left_child = get_left_child(i);
        int right_child = get_right_child(i);
        if(left_child < get_size() and massive[left_child] > massive[maximal_pos]){
            maximal_pos = left_child;
        }
        if(right_child < get_size() and massive[right_child] > massive[maximal_pos]){
            maximal_pos = right_child;
        }
        if(maximal_pos == i) return;
        swap(massive[maximal_pos], massive[i]);
        heapify_down(maximal_pos);
        // log(n)

    }

    void pop(){
        int last = get_size() - 1;
        int first = 0;
        swap(massive[first], massive[last]);
        massive.pop_back();
        heapify_down(first);
        // log(n)

    }

    void push(int el){
        massive.push_back(el);
        heapify_up(get_size() - 1);
        // log(n)

    }

    int get_size() {return massive.size();}

    int top() {
        if(get_size() == 0) return NULL;
        else return massive[0];
    }
    

};

void heapify_down(vector<int> & massive, int i){
    int maximal_pos = i;
    int left_child = (i * 2) + 1;
    int right_child = (i * 2) + 2;
    if(left_child < massive.size() and massive[left_child] > massive[maximal_pos]){
        maximal_pos = left_child;
    }
    if(right_child < massive.size() and massive[right_child] > massive[maximal_pos]){
        maximal_pos = right_child;
    }
    if(maximal_pos == i) return;
    swap(massive[maximal_pos], massive[i]);
    heapify_down(massive, maximal_pos);
    // log(n)
}

void build_heap(vector<int> & massive){
    int first_parent = ((massive.size() - 1) - 1) / 2;
    for(int i = first_parent; i >= 0; i--){
        heapify_down(massive, i);
    }
    // O(n)
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
    build_heap(massive); 
    for(int i = 0; i < n; i++){
        cout << massive[i] << " ";
    }


    endd
}