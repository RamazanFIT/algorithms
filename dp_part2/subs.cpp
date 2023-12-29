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

vector<vector<int> > dp(1005, vector<int>(1005, -1));

int rec(vector<int> & a, vector<int> & b, int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i >= a.size() || j >= b.size()) return 0;
    else if(a[i] == b[j]){
        dp[i][j] = 1 + rec(a, b, i + 1, j + 1);
    } else{
        
        dp[i][j] = max(rec(a, b, i + 1, j), rec(a, b, i, j + 1));
    }
    return dp[i][j]; //
}


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
    
    cout << rec(massive1, massive2, 0, 0) - 1;
    
    

    endd
}