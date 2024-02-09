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
vector<int> topsort;
void check(vector<set<int> > & g, int v, int start, vector<bool> & b){
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
set<int> cheking;
void dfs(vector<set<int> > &g, int v, vector<bool> &visited){
    visited[v] = 1;
    for(auto it : g[v]){
        if(!visited[it]){
            dfs(g, it, visited);
        }
    }
    if(cheking.find(v) == cheking.end())
    topsort.pb(v);
    cheking.insert(v);
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<set<int> > g(n + 1);
    vector<pair<int, int> > edges;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        edges.pb(make_pair(a, b));
    }

  
    if(!DAG(g)){
        cout << -1 << ENDL;
        endd
    }
    vector<bool> visited(n + 1);
    for(int i = 1; i <= n; i++){
        dfs(g, i, visited);
    }
    for(auto it = topsort.rbegin(); it != topsort.rend(); it++){
        cout << *it << " ";
    }

    
    endd
}