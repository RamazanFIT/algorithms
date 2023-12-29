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
vector<int> p;

int dsu_get(int v){
    if(v == p[v]){
        return v;
    } else{
        p[v] = dsu_get(p[v]);
        return p[v];
    }
}

void dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    if(rand() & 1){
        swap(a, b);
    }
    p[a] = b;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    p = vector<int>(n + 1);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    vector< pair < int, pair<int, int> > > g;
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g.pb({cost, {a, b}});
        g.pb({cost, {b, a}});
    }
    vector<pair<int, int>> rebra;
    int total_cost = 0;
    sort(all(g));

    for(int i = 0; i < 2 * m; i++){
        int a = g[i].ss.ff; int b = g[i].ss.ss;
        int cost = g[i].ff;
        if(dsu_get(a) != dsu_get(b)){
            rebra.pb(g[i].ss);
            total_cost += cost;
            dsu_union(a, b);
        }
    }
    cout << total_cost;
    

    endd
}