#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define ENDL "\n"
    #define ff first 
    #define ss second  
    #define pb push_back
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define endd return 0;
    #define repeat(x) for(int _ = 0; _ < x; _++)
    #define vii vector<int>
    #define mii map<int, int>
    #define vvi vector<vector<int>>
    #define FORW(leftb,rightb,way) for(int i = leftb; i < rightb; i+=way)
    #define FOR(leftb,rightb) for(int i = leftb; i < rightb; i+=1)
    #define print(massive) \
    for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
    using ll = long long;


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n + 1, vii(m + 1000, INT_MAX / 2));
        dp[1][1] = grid[0][0];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == 1 and j == 1) continue;
                // cout << dp[1][1] << " ";
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //         // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        //     }
        //     cout << ENDL;
        // }
    }

    

};

int main(){
        int n, m;cin >> n >> m;
        vvi some(n, vii(m));
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> some[i][j];
            }
        }

        Solution test;
        test.minPathSum(some);
    }
