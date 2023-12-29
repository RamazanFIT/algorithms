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
    vector<int> dp(n + 3, 0);
    
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 8;
    dp[3] = 21;
    for(int i = 4; i <= n; i++){
        dp[i] = (3 * dp[i - 1]) - dp[i - 2];
    }
    cout << dp[n] << ENDL;
    
    


    endd
}