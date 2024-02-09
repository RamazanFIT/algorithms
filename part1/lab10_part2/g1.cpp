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

void check(vector<unordered_set<int> > & g, int v, int start, vector<bool> & b){
    b[v] = true;
    if(!flag) return;
    
    for(auto vertex : g[v]){

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


bool DAG(vector<unordered_set<int> > & g){
    
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

    int n, m;
    cin >> n >> m;
    vector<unordered_set<int> > g(n + 1);
    vector<pair<int, int> > edges;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        edges.pb(make_pair(a, b));
    }

    for(auto it : edges){

        g[it.first].erase(it.second);
        
        if(DAG(g)){
            cout << "YES" << ENDL;
            endd
        }
        g[it.first].insert(it.second);

    }
    cout << "NO" << ENDL;
    endd
}