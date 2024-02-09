#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int n, m;

struct Node{
    Node * right = NULL;
    Node * left = NULL;
    Node * prev = NULL;
    int val = -1;
    Node(int val){
        this->val = val;
    }
};


vector<int> path;



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    cin >> n >> m;
    if(n == m){
        cout << 0;
        return 0;
    }
    if(n > m){
        cout << n - m << ENDL;
        for(int i = n - 1; i >= m; i--){
            cout << i << " ";
        }
        return 0;
    }
    int lower = 0;
    int upper = m;
    set<int> check;
    Node * tree = new Node(n);
    queue<Node*> q;
    q.push(tree);
    Node * cur;
    while(!q.empty()){
        Node * v = q.front();
        q.pop();
        int x_v = v->val * 2;
        int y_v = v->val - 1;
        if(lower < x_v and v->val <= upper and check.find(x_v) == check.end()){
            v->right = new Node(x_v);
            v->right->prev = v;
            q.push(v->right);
            check.insert(x_v);
        } 
        if(lower < y_v and y_v <= upper and check.find(y_v) == check.end()){
            v->left = new Node(y_v);
            v->left->prev = v;
            q.push(v->left);
            check.insert(y_v);

        }
        if(x_v == m){
            cur = v->right;
            break;
        }

        if(y_v == m){
            cur = v->left;  
            break;
        }
    }
    while(cur != NULL){
        path.pb(cur->val);
        cur = cur->prev;
    }

    cout << path.size() - 1 << ENDL;
    for(int i = path.size() - 2; i >= 0; i--){
        cout << path[i] << " ";
    }

    endd
}