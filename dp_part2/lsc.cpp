#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<vector<int> > dp(1005 + 1, vector<int>(1005 + 1, 0));

string rec(int i, int j, string & a, string & b){
    if(i <= 0 or j <= 0) return "";
    else{
        if(a[i - 1] == b[j - 1]){
            return rec(i - 1, j - 1, a, b) + a[i - 1];
        } else if(dp[i - 1][j] > dp[i][j - 1])
            return rec(i - 1, j, a, b);
        else 
            return rec(i, j - 1, a, b);
    }
    return "";
}

// string path[1005][1005];

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.size(); i++){
        for(int j =1 ; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1]){

               dp[i][j] = dp[i - 1][j - 1] + 1;


                
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // if(path[i - 1][j].size() >= path[i][j - 1].size()){
                //     path[i][j] = path[i - 1][j];
                // } else{
                //     path[i][j] = path[i][j - 1];
                // }
            }
        }
    }
    // cout << dp[a.size()][b.size()];
    // for(int i = 0; i <= a.size(); i++){
    //     for(int j = 0; j <= b.size(); j++) cout << dp[i][j] << " ";cout << ENDL;
    // }
    cout << rec(a.size(), b.size(), a, b) << ENDL;
    // cout << path[a.size()][b.size()] << ENDL;
// 0 0 0 0 0 0 0 
// 0 0 1 1 1 1 1 
// 0 0 1 1 1 2 2 
// 0 0 1 1 2 2 2 
// 0 0 1 2 2 2 3 
// 0 0 1 2 3 3 3 
// 0 0 1 2 3 4 4  
// 0 0 1 2 3 4 4  
    endd
}