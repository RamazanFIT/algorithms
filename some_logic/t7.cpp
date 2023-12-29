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
vector<int> path;


void dfs(vector<vector<int>> &g, int v, vector<int> &cnt_of_route, int way){
    for(auto vertex : g[v]){
        if(cnt_of_route[vertex] != 0){
            
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

    

    endd
}