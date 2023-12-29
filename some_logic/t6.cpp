#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define in :
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> top_sort;
vector<int> path;
int mod = 1e9 + 7;

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
    }
    int from = 1; int to = n;

    vector<int> cnt_of_route(n + 1);
    vector<bool> visited(n + 1);
    // for(int i = 1; i <= n; i++){
    //     if(!visited[i]) 
        dfs(g, 1, visited);

    // }
    cnt_of_route[1] = 1;
    reverse(all(top_sort));
    for(auto it in top_sort){
        for(auto vertex in g[it]){
            cnt_of_route[vertex] = (cnt_of_route[it] % mod + cnt_of_route[vertex] % mod) % mod;
        }
        // cout << it << " ";
    }

    cout << cnt_of_route[n] << ENDL;
    
    endd
}