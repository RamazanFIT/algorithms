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
    int n, k;
    cin>>n>>k;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    vector<int> dp(n);
    dp[0] = massive[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + massive[i];
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        cout << lower_bound(all(dp), a) - dp.begin() + 1 << ENDL;
    }
    
    


    endd
}