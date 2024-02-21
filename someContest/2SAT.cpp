// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> color, used, topsort;
vector<vector<int>> g, anti_g;


int getNumber(int i){
    if(i > 0)
    return 2 * i;
    return -2 * i + 1;
}

int inv(int i){
    return i ^ 1;
}

void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    
    for(auto w : g[v]){
        dfs(w);
    }
    topsort.pb(v);
}

void dfs2(int v, int cl){
    if(color[v] != -1) return;
    color[v] = cl;
    
    for(auto w : anti_g[v]){
        dfs2(w, cl);
    }
}

void slv(int ccase){
    int n, m;cin>> m >> n;
    topsort.clear();
    anti_g = g = vector<vector<int>>(2 * (n + 1));
    used = vector<int>(2 * (n + 1));
    color = vector<int>(2 * (n + 1), -1);

    repeat(m){
        int a, b;
        cin >> a >> b;
        a = getNumber(a);
        b = getNumber(b);
        
        g[inv(a)].pb(b);
        g[inv(b)].pb(a);

        anti_g[b].pb(inv(a));
        anti_g[a].pb(inv(b));
        
    }

    for(int i = 2; i <= 2 * n; i++){
        dfs(i);
    }
    
    reverse(all(topsort));
    int cl = 0;
    for(auto w : topsort){
        if(color[w] == -1){
            dfs2(w, cl++);
        }
    }
    vector<int> ans;
    // print(color);
    for(int i = 2; i <= 2 * n; i+=2){
        if(color[i] == -1 or color[inv(i)] == -1) continue;
        if(color[i] == color[inv(i)]){
            cout << "Case " << ccase << ": " << "No" << ENDL;
            return;
        }
        if(color[i] > color[inv(i)]){
            ans.pb(i / 2);
        }
    }
    cout << "Case " << ccase << ": " << "Yes" << ENDL;
    cout << ans.size() << " ";
    for(auto it : ans) cout << it << " "; cout << ENDL;

}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) slv(_ + 1);
    


    endd
}