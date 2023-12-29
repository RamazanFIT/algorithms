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

void dfs(vector<vector<int>> &g, vector<bool> &visited, int v){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex]){
            dfs(g, visited, vertex);
        }
    }
    top_sort.pb(v);
}
map<int, int> mapa;
void paint(vector<vector<int>> &g, vector<int> &color, int cl, int v){
    color[v] = cl;
    mapa[cl] = v;
    for(auto vertex : g[v]){
        if(color[vertex] == INT_MAX){
            paint(g, color, cl, vertex);
        }
    }
}

void create_new_graph(vector<vector<int>> &g, int v, int cl, 
vector<vector<int>> &new_graph_in, vector<vector<int>> &new_graph_out,  vector<bool> &visited, vector<int> &color){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex] and color[vertex] == cl){
            create_new_graph(g, vertex, cl, new_graph_in, new_graph_out, visited, color);
        } else if(color[vertex] != cl){
            new_graph_in[color[v]].pb(color[vertex]);
            new_graph_out[color[vertex]].pb(color[v]);
        }
    }
}

void t_sort(vector<vector<int>> &g, vector<bool> &visited, int v){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex]){
            t_sort(g, visited, vertex);
        }
    }
    top_sort.pb(v);
}

void get_ans(vector<vector<int>> &g, int v, vector<bool> &visited){
    visited[v] = true;

    for(auto vertex : g[v]){
        if(!visited[vertex]){
            get_ans(g, vertex, visited);
        }
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g_in(n + 1);
    vector<vector<int>> g_out(n + 1);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        g_in[a].pb(b);
        g_out[b].pb(a);
    }
    
    vector<int> color(n + 1, INT_MAX);
    
    vector<bool> visited(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(g_in, visited, i);
        }
    }
    reverse(all(top_sort));

    int cl = 1;
    // visited = vector<int>(n + 1);
    for(auto vertex : top_sort){
        if(color[vertex] == INT_MAX){
            paint(g_out, color, cl++, vertex);
        }
    }
    visited = vector<bool>(n + 1);
    
    vector<vector<int>> new_graph_in(cl);
    vector<vector<int>> new_graph_out(cl);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            create_new_graph(g_in, i, color[i], new_graph_in, new_graph_out, visited, color);
        }
    }

    top_sort.clear();
    visited = vector<bool>(n + 1);
    for(int i = 1; i < cl; i++){
        if(!visited[i]){
            t_sort(new_graph_out, visited, i);
        }
    }
    reverse(all(top_sort));
   
    vector<int> ans;
    visited = vector<bool>(n + 1);
    
    for(auto vertex : top_sort){
        if(!visited[vertex]){

            get_ans(new_graph_out, vertex, visited);
            ans.pb(vertex);
        }
    }

    cout << ans.size() << ENDL;
    for(auto vertex : ans){
        cout << mapa[vertex] << " ";
    }

    endd
}