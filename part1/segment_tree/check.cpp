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

int mod = 1e9 + 7;

signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    freopen("std2.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector < int > > dp(n + 1, vector<int>(k + 1));
    dp[1][0] = 1;
    // for(int i = 2; i <= n; i++){
    //     for(int j = 0; j <= k; j++){
    //         for(int k = 0; k <= i; k++){
    //             if(j - (i - k - 1) >= 0)
    //             dp[i][j] += dp[i - 1][j - (i - k - 1)];
    //         }
    //     }
    // }

    // cout << dp[n][k] << ENDL;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int c = 0; c < i; c++){
                if(j - (i - c - 1) >= 0ll) dp[i][j] += (dp[i - 1][j - (i - c - 1)] % mod);
            }
        }
    }
    cout << dp[n][k] % mod << ENDL;

    endd
}