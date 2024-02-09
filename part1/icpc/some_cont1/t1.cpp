#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int long long
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

signed main(){
    
    goodluck
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> dp(n + 2);
    vector<int> massive(n + 2);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    for(int i = 2; i < n + 2; i++){
        dp[i] = max(dp[i - 2] + massive[i - 2], dp[i - 1] + massive[i - 2]);
    }
    cout << dp[n + 1];

    
    


    endd
}