#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<bool> w;

bool flag = false;

void dfs_del(vector<set<int> > & g, int v){
    w[v] = true;
    if(flag){
        return;
    }
    for(auto vertex : g[v]){
        if(w[vertex] == 1){
            // g[v].erase(vertex);
            cout << v << " " << vertex << ENDL;
            flag = true;
            return;
        } else{
            dfs_del(g, vertex);
        }
    }
}

void dfs(vector<set<int> > & g, int v, vector<bool> & bolean){
    bolean[v] = true;
    
    for(auto vertex : g[v]){
        if(bolean[vertex]){
            cout << "NO" << ENDL;
            exit(0); 
        } else{
            dfs(g, vertex, bolean);
        }
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<set<int> > g(n + 1);
    vector<pair<int, int> > jojo;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        jojo.pb(make_pair(a, b));
    }
    // for(int i = 1; i <= n; i++){
    //     // dfs_del(g, i);
    //     if(flag){
    //         break;
    //     }
    // }
    // if(flag == false){
    //     cout << "YES" << ENDL;
    //     endd
    // } else{
    //     for(int i = 1; i <= n; i++){
    //         vector<bool> bolean(n + 1, 0);
    //         dfs(g, i, bolean);
    //     }
    // }
    // cout << "YES" << ENDL;
    
    for(int i = 0; i < jojo.size(); i++){
        // cout << jojo[i].ff << " " << jojo[i].ss << ENDL;
        g[jojo[i].ff].erase(jojo[i].ss);
        for(int j = 1; j <= n; j++){
            vector<bool> bolean(n + 1, 0);
            w = bolean;
            dfs_del(g, j);
        }
        if(flag == false){
            cout << "YES" << ENDL;endd
        }
        flag = false;
        g[jojo[i].ff].insert(jojo[i].ss);
    }
    cout << "NO" << ENDL;

    endd
}