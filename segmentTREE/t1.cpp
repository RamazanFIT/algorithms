// Bismillah 
// لا إله إلا الله محمد رسول الله
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
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;




void solve(int ccase){
    int n;cin>>n;
    // vii a(n), b(n);
    vector<vector<int>> mass(3, vector<int>(n + 1));

    // for(int i = 0; i < n; i++) cin >> a[i];
    // for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n ; j++){
            char a;
            cin >> a;
            // cin >> mass[i][j];
            mass[i][j] = (a - '0');
        }
    }
    vector<vector<int>> dp(3, vector<int>(n + 1));

    dp[0][0] = 0;
    dp[1][0] = 1;
    for(int i = 1; i < n; i++){


            if(dp[0][i - 1] + 1 == dp[1][i - 1]){
               
                if(mass[0][i] > mass[1][i - 1]){
                    dp[1][i] = dp[1][i - 1] + 1;
                    dp[0][i] = INT_MIN;

                } else if(mass[0][i] < mass[1][i - 1]){
                    dp[1][i] = dp[0][i - 1] + 2;
                    dp[0][i] = dp[1][i - 1];
                    dp[1][i - 1] = INT_MIN;
                } else{
                    dp[1][i] = dp[1][i - 1] + 1;
                    dp[0][i] = dp[1][i - 1];
                }

            } else{
                

                if(dp[1][i - 1] > (dp[0][i - 1] + 1)){
                    dp[1][i] = dp[1][i - 1] + 1;
                    dp[0][i] = INT_MIN;
                } else{
                    dp[0][i] = dp[0][i - 1] + 1;
                    dp[1][i] = dp[0][i - 1] + 2;
                    dp[1][i - 1] = INT_MIN;
                }
            }
    }
    

    // int ans;
    string s = "";
    // ans = 1;
    int i = 1;
    int j = n - 1;
    while(true){
        if(i <= 0 and j <= 0) break;
        if(i != 0 and dp[i][j] - 1 == dp[i - 1][j]){
            s += mass[i][j] + '0';
            i--;
        } else{
            s += mass[i][j] + '0';
            j--;
        }
    }
    // for(int i = n - 1; i >= 1; i--){
        // if((dp[1][i] - 1 == dp[0][i]) and (dp[0][i] == dp[1][i - 1])){
        //     ans++;
        // }
    // }
    
    s += mass[0][0] + '0';
    reverse(all(s));
    cout << s << ENDL;
    // cout << ans << ENDL;

    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}