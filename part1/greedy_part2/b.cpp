#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<set<pair<int, int> > > g(n + 1);

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         int a;
    //         cin >> a;
    //         if(a == 1){
    //             g[i].insert(j);
    //         }
    //     }
    // }
    for(int i = 0; i < m; i++){
        int x, y, d; cin >> x >> y >> d;
        g[x].insert(make_pair(y, d));
    }
    int x = 1, y = n;
    // cin >> x >> y;
    queue<int> q;
    vector<int> dp(n + 1, INT_MAX);
    dp[x] = 0;
    q.push(x);
    while(!q.empty()){
        for(auto it : g[q.front()]){
            
            if(dp[q.front()] + it.ss < dp[it.ff]){
                dp[it.ff] = dp[q.front()] + 1;
                q.push(it.ff);
            }
        }
        q.pop();
    }
    if(dp[y] != INT_MAX)
    cout << dp[y] << ENDL;
    else cout << -1;
    


    endd
}