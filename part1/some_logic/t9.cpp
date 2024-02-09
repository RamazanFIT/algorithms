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
vector<int> top_sort;
vector<int> path;


void dfs(vector<vector<int>> &g, int v, vector<bool> &visited){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex]){
            dfs(g, vertex, visited);
        }
    }
    top_sort.pb(v);
}

void get_path(vector<vector<int>> &g, int v, vector<int> &cnt){
    path.pb(v);
    if(v == 1){
        return;
    }
    for(auto vertex : g[v]){
        if(cnt[vertex] + 1 == cnt[v]){
            get_path(g, vertex, cnt);
        }
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<vector<int>> g2(n + 1);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g2[b].pb(a);
    }
    int from = 1; int to = n;

    vector<int> cnt_of_route(n + 1);
    vector<bool> visited(n + 1);
    dfs(g, from, visited);
    cnt_of_route[1] = 1;
    reverse(all(top_sort));
    for(auto vertex : top_sort){
        if(vertex == 1) continue;
        for(auto v : g[vertex]){
            // cnt_of_route[v] = max(cnt_of_route[vertex] + 1, cnt_of_route[v]);
            
        }
    }
    if(cnt_of_route[to] == 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    get_path(g2, to, cnt_of_route);
    cout << path.size() << ENDL;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    endd
}