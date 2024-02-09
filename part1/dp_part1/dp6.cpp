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
    freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // O(n);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    vector<int> w(n + 1, 0);
    w[1] = dp[1];
    for(int i = 2; i <= n; i++){
        dp[i] = w[i - 1] - w[max(0, i - k - 1)];
        w[i] = w[i - 1] + dp[i];
    }
    cout << dp[n] << ENDL;
    


    endd
}