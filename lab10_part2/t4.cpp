#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

bool flag = true;

void check(vector<set<int> > & g, int v, int start, vector<bool> & b){
    b[v] = true;
    if(!flag) return;
    
    for(auto vertex : g[v]){
        // cout << vertex  << " " << start << ENDL; 
        if(vertex == start){
            flag = false;
            return;
        }
        if(b[vertex]) continue;
        if(!flag) return;
        check(g, vertex, start, b);
        if(!flag) return;
    }
    
}


bool DAG(vector<set<int> > & g){
    
    int cnt = 0;
    int c = 0;
    for(int i = 1; i < g.size(); i++){
        vector<bool> b(g.size());
        check(g, i, i, b);
        if(!flag){
            flag = true;
            return false;
        }
    }
    flag = true;
    return true;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<set<int> > g(n + 1);
    vector<pair<int, int> > edges;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a){
                g[i].insert(j);
            }
        }
    }
    if(DAG(g)){
        cout << 0;
        return 0;
    }
    cout << 1 << ENDL;
    endd
}