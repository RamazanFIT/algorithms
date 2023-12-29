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
    if(p[v] == v) return v;
    else{
        p[v] = dsu_get(p[v]);
        return p[v];
    }
}

void dsu_merge(int x, int y){
    x = dsu_get(x);
    y = dsu_get(y);
    if(rand() & 1) swap(x, y);
    p[x] = y;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g;
    p = vector<int>(n + 1);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g.pb({cost, {a, b}});
        g.pb({cost, {b, a}});
    }
    sort(all(g));
    for(int i = 0; i < 2 * m; i++){
        int a = g[i].ss.ff;
        int b = g[i].ss.ss;
        int w = g[i].ff;
        if(dsu_get(a) != dsu_get(b)){
            cout << a << " " << b << ENDL;
            dsu_merge(a, b);
        }
    }


    


    endd
}