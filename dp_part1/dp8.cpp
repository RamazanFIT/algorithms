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
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];
    int k;
    cin >> k;
    vector<int> dp(n + 1);
    dp[0] = INT_MAX;
    dp[1] = numbers[0];
    for(int i = 2; i <= n; i++){
        
        int samyi_min = INT_MAX;
        for(int j = 0; j < k; j++){
            if(i - j - 1 >= 0)
            samyi_min = min(samyi_min, dp[i - j - 1]);
        }
        dp[i] = samyi_min + numbers[i - 1];
    }

    cout << dp[n] << ENDL;
    
// 35734
// 35734
    endd
}