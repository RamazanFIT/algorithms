#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
bool w[100000 * 2];
int x, y;

void dfs(vector<set<int> > & g, int v){
    if(w[v]){
        return;
    } else{
        if(v == y){
            cout << "YES" << ENDL;
            exit(0);
        }
        w[v] = true;
        for(auto vertex : g[v]){
            dfs(g, vertex);
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
    for(int i = 1 ; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }


    cin >> x >> y;

    dfs(g, x);
    cout << "NO" << ENDL;
    


    endd
}