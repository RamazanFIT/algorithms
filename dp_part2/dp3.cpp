#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int MAXX = 50000;
vector<int> dp(MAXX, -1);

int dfs(vector<set<int> > & graph, vector<set<int> > & ko, int vertex){
    if(dp[vertex] != -1) return dp[vertex];
    for(auto v : ko[vertex]){
        dp[vertex] = max(dp[vertex], dfs(graph, ko, v) + 1);
    }

    return 0;
}


signed main(){
    
    goodluck
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<set<int> > graph(n + 1);
    vector<set<int> > ko(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        ko[b].insert(a);
    }
    
    for(int i = 1; i <= n; i++){
        dfs(graph, ko, i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << ENDL;

    endd
}