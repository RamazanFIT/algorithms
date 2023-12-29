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
vector<int> top_sort;

void dfs(vector<vector<int>> &g_in, int v, vector<bool> &visited){
    visited[v] = true;

    for(auto vertex : g_in[v]){
        if(!visited[vertex]){
            dfs(g_in, vertex, visited);
        }
    }
    top_sort.pb(v);
}

void condensation(vector<vector<int>> &g_out, 
                    int v, vector<bool> &visited, 
                    int cl, vector<int> &color){
    visited[v] = true;
    color[v] = cl;
    // cout << v << " " << cl << ENDL;
    for(auto vertex : g_out[v]){
        if(!visited[vertex]){
            condensation(g_out, vertex, visited, cl, color);
        }
    }
}

vector<pair<int, int>> new_graph;

void dfs_top_sort(vector<vector<int>> &g_in, 
                int v, 
                vector<bool> &visited, 
                int cl,
                vector<int> &color){
    
    visited[v] = true;
    for(auto vertex : g_in[v]){
        if(color[vertex] == cl && !visited[vertex]){
            dfs_top_sort(g_in, vertex, visited, cl, color);
        } else if(color[vertex] != cl){
            new_graph.pb({cl, color[vertex]});
        }
    }

}





signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> color(n + 1, INT_MAX);
    vector<vector<int>> g_in(n + 1);
    vector<vector<int>> g_out(n + 1);
    vector<bool> visited(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;cin>>a>>b;
        g_in[a].pb(b);
        g_out[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(g_in, i, visited);
        }
    }
    reverse(all(top_sort));
    int cnt = 1;
    vector<int> kkk(n + 1);
    // for(auto it : top_sort) cout << it << " ";
    visited = vector<bool>(n + 1, 0);
    for(auto vertex : top_sort){
        if(!visited[vertex]){
            condensation(g_out, vertex, visited, cnt, color);
            cnt++;
        }
        kkk[color[vertex]]++;
    }

    visited = vector<bool>(n + 1, 0);

    for(auto vertex : top_sort){
        if(!visited[vertex]) 
        dfs_top_sort(g_in, vertex, visited, color[vertex], color);
    }


    cout << cnt - 1 << ENDL;
    

    // visited = vector<bool>(n + 1, 0);
    
    // vector<vector<int>> graph_new(cnt);
    // for(auto v : new_graph){
    //     graph_new[v.ff].pb(v.ss);
    //     // cout << v.ff   << " " <<    v.ss << ENDL;
    // }
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    // top_sort.clear();
    // for(int i = 1; i < cnt; i++){
    //     if(!visited[i])
    //     dfs(graph_new, i, visited);
    // }
    // for(auto vertex : top_sort){
    //     cout << color[vertex] << " ";
    // }
    // reverse(all(top_sort));
    // cnt = 1;
    // for(auto vertex : top_sort){
    //     cout << vertex << " " << kkk[vertex] << ENDL;
    // }
    // for(auto vertex : top_sort){
    //     for(int i = 0; i < kkk[vertex]; i++){
    //         cout << cnt << " ";
    //     }
    //     cnt++;
    //     // cout << vertex << " ";
    // }

    endd
}