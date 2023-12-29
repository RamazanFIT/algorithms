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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > massive(n + 1, vector<int>(m + 1, 0));

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0] = __LONG_LONG_MAX__;
    }
    for(int i = 0; i <= m; i++){
        dp[0][i] = __LONG_LONG_MAX__;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> massive[i][j];
        }
    }
    dp[1][1] = massive[1][1];
    for(int i = 2; i <= m; i++){
        dp[1][i] += dp[1][i - 1] + massive[1][i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + massive[i][j];
        }
    }
    cout << dp[n][m] << ENDL;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     } cout << ENDL;
    // }
    int i = n;
    int j = m;
    // cout << 1 << " " << 1 << ENDL;
    
    vector<pair<int, int> > path;
    set<pair<int, int> > jojo;
    path.push_back(make_pair(n, m));
    jojo.insert(make_pair(n, m));
    while(true){
        bool flag = true;
        int c = dp[i][j] - massive[i][j];
        if(c == dp[i - 1][j]){
            i = i - 1;
            if(jojo.find(make_pair(i, j)) == jojo.end()){
            path.push_back(make_pair(i, j));
            jojo.insert(make_pair(i, j));}
            flag = false;
        } else if(c == dp[i][j - 1]){
            j--;
            if(jojo.find(make_pair(i, j)) == jojo.end()){
            path.push_back(make_pair(i, j));
            jojo.insert(make_pair(i, j));}
            flag = false;
        }
        if(flag){
            break;
        }
    }
    if(jojo.find(make_pair(1, 1)) == jojo.end())
    path.push_back(make_pair(1, 1));
    for(auto it = path.rbegin(); it != path.rend(); it++){
        cout << it->first << " " << it->second << ENDL;
    }
    // cout << i << " " << j << ENDL;
    // cout << i << " " << j << ENDL;
    endd
}