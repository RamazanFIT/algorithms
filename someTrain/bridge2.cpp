// // Bismillah
// #include <bits/stdc++.h>
// #define ENDL "\n"
// #define ff first 
// #define ss second  
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define endd return 0;
// #define int ll
// #define repeat(x) for(int _ = 0; _ < x; _++)
// #define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
// #define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
// using ll = long long;
// using namespace std;
// vector<int> timer, up, in, color;
// vector<bool> visited;
// vector<vector<pair<int, int>>> g;
// set<int> bridges;
// int T = 0;
// int n;


// void mark(int v, int u, int cl){
//     if(color[v] != 0) return;
//     color[v] = cl;
//     for(auto w : g[v]){
//         if(w.ff == u) continue;
//         mark(w.ff, v, cl);
//     }
// }

// void dfs(int v, int u){
//     // u
//     // .
//     // .
//     // .
//     // v
//     visited[v] = true;
//     in[v] = up[v] = T++;
    
//     bool flag = true;
//     int f;
//     for(auto w : g[v]){
//         if(flag and w.ff == u) {flag = true; f = w.ss; continue;}
//         if(!visited[w.ff]) {
//             dfs(w.ff, v);
//             up[v] = min(up[v], up[w.ff]);
//         } else{
//             up[v] = min(up[v], up[w.ff]);
//         }
//     }
//     if(up[v] == in[v] and v != u){ // or >= тоже подейдет(но такого никогда не будет)
//         // That is bridge 
//         // mark(v, u, in[v]);
//         bridges.insert(f);
//     }
// }



// void solve(){
//     // int n, m;cin>>n>>m;
//     int m;
//     cin >> m;
//     g = vector<vector<pair<int, int>>>(n + 1);
//     timer = up = in = color = vector<int>(n + 1);
//     visited = vector<bool>(n + 1);
//     T = 0;
//     bridges.clear();
//     repeat(m){
//         int x, y;
//         cin >> x >> y;
//         g[x].pb({y, _ + 1});
//         g[y].pb({x, _ + 1});
//     }
//     for(int i = 1; i <= n; i++){
//         if(!visited[i]){
//             dfs(i, i);
//         }
//     }
//     // sort(all(bridges));
//     cout << bridges.size() << ENDL;
//     for(auto it : bridges){
//         cout << it << ENDL;
//     }
    
// }

// signed main(){
    
//     goodluck
//     // freopen("std.in", "r", stdin);
//     // freopen("std.out", "w", stdout);

//     while(cin >> n)
//     solve();

//     endd
// }