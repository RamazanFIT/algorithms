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
    // freopen("slalom.in", "r", stdin);
    // freopen("slalom.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int> > dp(n + 2, vector<int>(n + 2, INT_MIN));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    } 
    cout << ans << ENDL;
    


    endd
}