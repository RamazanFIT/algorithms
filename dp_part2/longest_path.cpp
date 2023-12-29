#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int MAXX = 50000;
vector<int> dp(MAXX, -1);

int dfs(vector<set<int> > & ko, int vertex){
    if(dp[vertex] != -1) return dp[vertex];
    for(auto v : ko[vertex]){
        dp[vertex] = max(dp[vertex], max(dfs(ko, v), 0ll) + 1);
    }
    return dp[vertex];
}


signed main(){
    
    goodluck
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<set<int> > ko(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ko[b].insert(a);
    }
    
    for(int i = 1; i <= n; i++){
        dfs(ko, i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << ENDL;

    endd
}