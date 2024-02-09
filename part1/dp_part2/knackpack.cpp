#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

const int MAXX = 1e5 + 10;

int dp[400][20000];


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    int m;
    cin >> m >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(massive[i] <= j){
                int vzyal = j - massive[i];
                dp[i + 1][j] = max(massive[i] + dp[i][vzyal], dp[i][j]);
            } else{
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    cout << dp[n][m] << ENDL;
    

    


    endd
}