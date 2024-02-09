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

void dfs(vector<vector<int>> &g, int v, vector<bool> &visited){
    visited[v] = true;

    for(int i = 0; i < g[v].size(); i++){
        if(visited[g[v][i]]) continue;

        dfs(g, g[v][i], visited);
    }
}

vector<int> path;


void get_path(vector<vector<int>> &g, int v, vector<bool> &visited, vector<int> &cost){
    path.pb(v);
    if(v == 1){
        return;
    }
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        if(visited[g[v][i]]) continue;
        
        if(cost[v] - 1 == cost[g[v][i]]){
            get_path(g, g[v][i], visited, cost);
            return;
        }
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    a = "X" + a + "-X";
    b = "X" + b + "-X";
    vector<vector<int>> g(2 * n + 2);
    vector<vector<int>> g2(2 * n + 2);

    for(int i = 1; i <= n; i++){
        if(a[i] == 'X') continue;
        if(a[i - 1] != 'X'){
            g[i].pb(i - 1);
            g2[i - 1].pb(i);
        }
        if(a[i + 1] != 'X'){
            g[i].pb(i + 1);
            g2[i + 1].pb(i);

        }
        if(i + k >= n + 1){
            g[i].pb(2 * n + 1);
            g2[2 * n + 1].pb(i);
        } else if(b[i + k] != 'X'){
            g[i].pb(i + k + n);
            g2[i + k + n].pb(i);

        }
    }
    for(int i = 1; i <= n; i++){
        if(b[i] == 'X') continue;
        if(b[i - 1] != 'X'){
            g[i + n].pb(i - 1 + n);
            g2[i - 1 + n].pb(i + n);

        }
        if(b[i + 1] != 'X'){
            g[i + n].pb(i + 1 + n);
            g2[i + 1 + n].pb(i + n);

        }
        if(i + k >= n + 1){
            g[i + n].pb(2 * n + 1);
            g2[2 * n + 1].pb(i + n);
        } else if(a[i + k] != 'X'){
            g[i + n].pb(i + k);
            g2[i + k].pb(i + n);
        }
    }

    vector<bool> visited(2 * n + 2);
    
 
    vector<int> cost(2 * n + 2, INT_MAX);
    queue<int> q;
    cost[1] = 0;
    q.push(1);
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        
        for(int i = 0; i < g[vertex].size(); i++){
            if(cost[vertex] + 1 < cost[g[vertex][i]]){
                cost[g[vertex][i]] = cost[vertex] + 1;
                q.push(g[vertex][i]);
            }
        }
    }
    get_path(g2, 2 * n + 1, visited, cost);
    vector<int> check(2 * n + 2);
    for(int i = 1; i <= n; i++){
        check[i] = i;
        check[i + n] = i;
    }
    if(cost[2 * n + 1] == INT_MAX){
        cout << "NO" << ENDL;
        return 0;
    }
    int cnt = 0;
    for(int i = path.size() - 1; i >= 1; i--){

        if(check[path[i]] <= cnt){
            cout << "NO";
            return 0;
        }
        cnt++;
    }
    cout << "YES" << ENDL;
    
    endd
}