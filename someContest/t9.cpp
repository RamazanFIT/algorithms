// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
const int MAXN = 62;
int dp[MAXN][MAXN];


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s;
    cin >> s;
    int n = s.size();
    // for(int i = 0; i < n; i++){
    //     dp[i][i] = 1;
    // }
    for(int l = 1; l < n; l++){
        for(int i = 0; i + l < n; i++){
            int j = i + l;
            if(s[i] == s[j]){
                // dp[i][j] = dp[i][j - 1] - dp[i + 1][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + dp[i + 1][j - 1] + dp[i + 1][j - 1] + 1;
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
            } else{
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
        }
    }
    cout << dp[0][n - 1];
    endd
}