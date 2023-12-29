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


void dfs(vector<set<int> > &g, int v, vector<bool> &visited){
    visited[v] = 1;
    for(auto it : g[v]){
        if(!visited[it]){
            cout << v << " " << it << ENDL;
            dfs(g, it, visited);
        }
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<set<int> > g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    
    }
    // vector<bool> visited(n + 1);
    // dfs(g, 1, visited);
    cout << "YES";
    
    


    endd
}