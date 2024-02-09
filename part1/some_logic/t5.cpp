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

vector<pair<int, int>> ans;
int T = 0;

void dfs(vector<vector<int>> &g, int current, int from, 
        vector<bool> &visited, vector<int> &t_in, vector<int> &up){
    visited[current] = true;
    t_in[current] = T++;
    up[current] = t_in[current]; // INT_MAX
    for(auto vertex : g[current]){
        if(vertex == from){
            continue;
        }
        if(!visited[vertex]){
            dfs(g, vertex, current, visited, t_in, up);
            up[current] = min(up[current], up[vertex]);
        } else{
            up[current] = min(up[current], t_in[vertex]);
        }
    }
    if(up[current] >= t_in[current] and current != from){
        // ans.pb({from, current});
        if(from > current){
            ans.pb({current, from});
        } else{
            ans.pb({from, current});
        }
    }
}
void solve(int ccase){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        string s;
        cin >> s;
        string tmp = "";
        int k;
        for(int j = 1; j < s.size() - 1; j++){
            tmp += s[j];
        }
        k = stoi(tmp);
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            g[v].pb(a); // problem

        }

    }
    vector<int> t_in(n);
    vector<int> up(n);
    vector<bool> visited(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(g, i, i, visited, t_in, up);
        }
    }
    cout << "Case " << ccase << ":" << ENDL;
    cout << ans.size() << " critical links" << ENDL;
    sort(all(ans));
    for(auto v : ans){
        cout << v.first << " - " << v.second << ENDL;
    }
    T = 0;
    ans.clear();
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int t;
    cin >> t;
    // while(t--) solve();
    for(int i = 1; i <= t; i++){
        solve(i);
    }


    endd
}