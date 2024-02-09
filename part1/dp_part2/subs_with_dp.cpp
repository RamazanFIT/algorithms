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

vector<vector<int> > dp(1005, vector<int>(1005, 0));



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive1(n + 1);
    for(int i = 1; i <= n; i++) cin >> massive1[i];
    
    
    int m;
    cin >> m;
    vector<int> massive2(m + 1);
    for(int i = 1; i <= m; i++) cin >> massive2[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(massive1[i] == massive2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << ENDL;
    
    

    endd
}