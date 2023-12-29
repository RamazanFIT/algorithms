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

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++){
        for(int j = 1; j <= i / 2; j++){
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
        for(int j = 1; j <= sqrt(i) + 1; j++){
            if(i % j == 0){
                dp[i] = min(dp[i], dp[j] + dp[i / j]);
            }
        }
    }
    cout << dp[n] << ENDL;
    
    endd
}