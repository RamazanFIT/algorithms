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
    vector<int> massive(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> massive[i];
    }

    sort(massive.begin() + 1, massive.end());
    // for(auto i : massive) cout << i << " "; cout << ENDL;
    vector<int> dp(n + 1, 0);
    
    dp[1] = 0;
    dp[2] = massive[2] - massive[1];
    dp[3] = dp[2] + massive[3] - massive[2];
    for(int i = 4; i <= n; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + massive[i] - massive[i - 1];
    }
    cout << dp[n] << ENDL;
    endd
}