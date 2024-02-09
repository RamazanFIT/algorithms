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
vector<vector<int>> g;
vector<bool> point_of_dig;
vector<bool> visited;
vector<int> up;
vector<int> t_in;
int Timer;


int dfs(int v, int p){
    visited[v] = true;
    t_in[v] = Timer++;
    up[v] = t_in[v]; // INT_MAX
    // bool OK = true;
    int baby = 0;
    for(auto vertex : g[v]){
        if(vertex == p) continue;
        if(!visited[vertex]){
            baby++;
            dfs(vertex, v);
            up[v] = min(up[v], up[vertex]);
            if(up[vertex] >= t_in[v]){
                point_of_dig[v] = true;
            }
        } else{
            up[v] = min(up[v], t_in[vertex]);
        }
        
        
    }
    return baby > 1;
}
void solve(int t){
    int n, m;
    cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    up = vector<int>(n + 1);
    t_in = vector<int>(n + 1);
    visited = vector<bool>(n + 1);
    point_of_dig = vector<bool>(n + 1);
    Timer = 0;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            point_of_dig[i] = dfs(i, i);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(point_of_dig[i]) cnt++;
    }
    cout << "Case " << t << ": " << cnt << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i+=1){
        solve(i);
    }


    endd
}