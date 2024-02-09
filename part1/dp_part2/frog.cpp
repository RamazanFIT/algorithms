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

    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }

    vector<int> dp(n + 1);
    dp[2] = abs(massive[1] - massive[0]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(abs(massive[i - 1] - massive[i - 2]) + dp[i - 1], abs(massive[i - 1] - massive[i - 3]) + dp[i - 2]);
    }
    cout << dp[n] << ENDL;
    


    endd
}