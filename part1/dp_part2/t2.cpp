#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int dp[2000];

signed main(){
    
    goodluck
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

    int n;
    cin >> n;
    int w[n];
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(a == '"'){
            w[i] = 1;
        } else if(a == 'w'){
            w[i] = -3000;
        } else{
            w[i] = 0;
        }
    }
    // for(int i = 0; i < n; i++) cout << w[i] << "  "; cout << endl;
    for(int i = 0; i < 5; i++){
        dp[i] = -3000;
    }
    dp[5] = w[0];
    for(int i = 6; i < n + 5; i++){
        // cout << max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) << " ";
        dp[i] = max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) + w[i - 5];
        
    }
    if(dp[n + 4] >= 0)
    cout << dp[n + 4];
    else cout << -1 << ENDL;
    
    


    endd
}