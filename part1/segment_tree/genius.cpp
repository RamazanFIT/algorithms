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
    // freopen("std1.out", "w", stdout);
    int mod = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    
    vector<vector < int > > dp(n + 1, vector<int>(k + 1, 0));
    dp[1][0] = 1;

    vector<vector <int> > sum(n + 1, vector<int>(k + 1, 0));
    for(int i = 0; i <= k; i++){
        sum[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
          
            if(j - i >= 0)
            dp[i][j] = ((sum[i - 1][j]) - (sum[i - 1][j - i])) % mod;
            else dp[i][j] = sum[i - 1][j];
           
            if(j - 1 >= 0)
            sum[i][j] = ((sum[i][j - 1]) + (dp[i][j])) % mod; 
            else sum[i][j] = dp[i][j] % mod;
           
        }
        
    }
    // cout << dp[n][k] << ENDL;
    while(dp[n][k] < 0){
        dp[n][k] += mod;
        dp[n][k] %= mod;
    }

    cout << dp[n][k] << ENDL;
    endd
}