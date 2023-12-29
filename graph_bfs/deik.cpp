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
int x, y;

vector<int> ans;

void walk(int v, vector<int> & cost, vector<set<int> > &g){
    ans.pb(v);
    if(v == x){
        return;
    }
    for(auto vertex : g[v]){
        if(cost[v] - 1 == cost[vertex]){
            walk(vertex, cost, g);
            return;
        }
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    cin >> x >> y;
    vector<set<int> > g(n + 1);
    vector<int> cost(n + 1, INT_MAX);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    cost[x] = 0;
    
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        for(auto vertex : g[q.front()]){
            if(cost[vertex] == INT_MAX){
                cost[vertex] = cost[q.front()] + 1;
                q.push(vertex);
            }
        }
        q.pop();
    }
    if(cost[y] == INT_MAX){
        cout << -1;
        return 0;
    }
    walk(y, cost, g);
    cout << cost[y] << ENDL;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    


    endd
}