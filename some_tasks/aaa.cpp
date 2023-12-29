#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int sum = 0;
    for(int i = 1; i < n; i++){
        vector<int> cost(n + 1, INT_MAX);
        queue<int> q; q.push(i);
        cost[i] = 0;
        while(!q.empty()){
            int v = q.front();q.pop();
            for(int vertex : g[v]){
                if(cost[v] + 1 < cost[vertex]){
                    cost[vertex] = cost[v] + 1;
                    q.push(vertex);
                }
            }
        }
        for(auto j = i; j <= n; j++){
            sum += cost[j];
        }
    }
    cout << sum;


    endd
}