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


void dfs(vector<vector<int>> & g, int v, vector<bool> &b, vector<vector<int>> & g2){
    b[v] = true;

    for(auto vertex : g[v]){
        if(!b[vertex]){
            g2[v].pb(vertex);
            dfs(g, vertex, b, g2);
        }
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> b(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!b[i]){
            vector<bool> visited(n + 1);
            vector<vector<int>> g2(n + 1);
            dfs(g, i, visited, g2);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int vertex = q.front();q.pop();
                if(b[vertex]) continue;
                b[vertex] = true;
                for(auto v : g2[vertex]){
                    if((g2[v].size()) > g2[vertex].size()){
                        ans++;

                    }
                    q.push(v);
                }
            }
            ans++;
            
        } 


    }
    
    cout << ans << ENDL;

    endd
}