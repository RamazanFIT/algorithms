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

vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, component;
vector<bool> exists;

void dfs1 (int v) {
    if(used[v]) return;
    used[v] = true;
    // bool flag = false;
    for(auto w : g[v]){
        dfs1(w);
        // flag = true;
    }
    // if(flag)
    order.pb(v);
}

void dfs2 (int v, int cl) {
    if(component[v] != -1) return;
	component[v] = cl;
    for(auto w : gt[v]){
        dfs2(w, cl);
    }
}

int inv(int v){
    return v ^ 1;
}

int getNum(int v){
    if(v > 0) return 2 * (v - 1);
    return 2 * (-v - 1) + 1;
}

void solve(int ccase){
    int n, m;cin>> m >> n;
    g = gt = vector<vector<int>>(2 * (n + 1));
    exists = used = vector<bool>(2 * (n + 1));
    component = vector<int>(2 * (n + 1), -1);
    order.clear();
    repeat(m){
        int a, b;cin>>a>>b;
        a = getNum(a);
        b = getNum(b);
        exists[a] = true;
        exists[b] = true;
        exists[inv(a)] = true;
        exists[inv(b)] = true;
        g[inv(a)].pb(b);
        g[inv(b)].pb(a);

        gt[b].pb(inv(a));
        gt[a].pb(inv(b));
        
    }

    for(int i = 1; i <= 2 * n; i++){
        if(exists[i])
        if(!used[i]){
            dfs1((i));
        }
    }
    reverse(all(order));
    int cl = 0;
    for(int i = 0; i < order.size(); i++){
        if(exists[i])
        if(component[order[i]] == -1){
            dfs2(order[i], ++cl);
        }
    }

    for(int i = 1; i <= 2 * n; i++){
        if(exists[i])
        if(component[(i)] == component[inv((i))] and component[(i)] != -1 and component[inv((i))] != -1){
            cout << "Case " << ccase << ": " << "No" << ENDL;
            return;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        // if(component[getNum(i)] == -1 or component[inv(getNum(i))] == -1) continue;
        if(exists[i])
        if(component[getNum(i)] > component[inv(getNum(i))]){
            ans.pb(i);
        }

    }
    cout << "Case " << ccase << ": " << "Yes" << ENDL;

    cout << ans.size() << " ";
    for(auto it : ans){
        cout << it << " ";
    }
    // cout << ENDL;
    // for(int i = 1; i <= n; i++){
    //     cout << i  << " " << component[getNum(i)] << ENDL;
    //     cout << i  << " " << component[inv(getNum(i))] << ENDL;
    // }

   

}

signed main(){

    // freopen("std.out", "w", stdout);
    
    goodluck
    
    int t;cin>>t;repeat(t) solve(_ + 1);


    endd
}