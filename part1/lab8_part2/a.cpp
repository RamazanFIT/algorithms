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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j] = dp[max(i - 1, 0ll)][max(j - 2, 0ll)] + dp[max(i - 2, 0ll)][max(j - 1, 0ll)];
        }
    }
    cout << dp[n][m] << ENDL;
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     } 
    //     cout << ENDL;
    // } 


    endd
}