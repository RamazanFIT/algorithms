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
    // O(n * k);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
            } 
        }
    }
    cout << dp[n] << ENDL;
    


    endd
}