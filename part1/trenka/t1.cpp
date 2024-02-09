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
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<char>> massive(n + 2, vector<char>(m + 2, 'o'));
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            cin >> massive[i][j];
        }
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(massive[j][i] == '*'){
                dp[j][i] = dp[j - 1][i] + 1;
            } else if(massive[j][i] == '.'){
                dp[j][i] = dp[j - 1][i];
            }
        } 
        int j = n + 1;
        while(true){
            if(j == 0) break;
            if(massive[j][i] == 'o'){
                int jkjk = dp[j - 1][i];
                j--;
                repeat(jkjk){
                    // if(j == 0) break;
                    massive[j][i] = '*';
                    j--;
                }
            } else{
                massive[j][i] = '.';
                j--;
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            cout << massive[i][j];
        }
        cout << ENDL;
    }
    

    
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    repeat(n){
        solve();
    }
    
    


    endd
}