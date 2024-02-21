// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<bool> visited, isCut;
vector<int> in, up;
vector<vector<int>> g;
int T = 0;

bool dfs(int v, int u){
    visited[v] = true;
    in[v] = up[v] = T++;
    int baby = 0;
    for(auto w : g[v]){
        if(w == u){
            continue;
        }
        if(!visited[w]){
            dfs(w, v);
            baby++;
            up[v] = min(up[v], up[w]);
            if(up[w] >= in[v]){
                isCut[v] = true;
            }
        }  else{
            up[v] = min(up[v], in[w]);
        }

    }
    return baby > 1;
}

void solve(int xxxx){
    int n, m;
    cin >>  n >> m;
    isCut = vector<bool>(n +1);
    visited = vector<bool>(n +1);
    g = vector<vector<int>>(n + 1);
    in  = vector<int>(n + 1);
    up = vector<int>(n + 1);
    int T = 0;

    repeat(m){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]) 
        isCut[i] = dfs(i, i);
    }
    int cnt = 0;
    for(int i =1 ; i <= n; i++){
        // if(isCut[i]) cnt++;
        cout << isCut[i] << " ";
    }
    cout << "Case " <<  xxxx + 1 << ": " << cnt << ENDL; 
}
signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int x;
    cin >> x;
    repeat(x) solve(_);


    endd
}