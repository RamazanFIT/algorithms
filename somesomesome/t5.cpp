/* 
    Bismillah 
 لا إله إلا الله محمد رسول الله
 Al'-Phatixa
 بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 ٱلْحَمْدُ لِلَّهِ رَبِّ ٱلْعَٰلَمِينَ
 ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 مَٰلِكِ يَوْمِ ٱلدِّينِ
 إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ
 ٱهْدِنَا ٱلصِّرَٰطَ ٱلْمُسْتَقِيمَ
 صِرَٰطَ ٱلَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ ٱلْمَغْضُوبِ عَلَيْهِمْ وَلَا ٱلضَّآلِّينَ
*/
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define int ll
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
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;

using ll = long long;
using namespace std;

void solve(int ccase){
    int x, y;cin>>x>>y;
    // cout << x * y / 2; 
    // if(x == 2 and y == 6){
    //     cout << 10 << ENDL;
    // } else{
    //     cout << -1 << ENDL;
    // }
    int n = 10;
    vvi dp(n + 2, vii(n + 2));
    
    // for(int i = 2; i <= n; i+=2) w[1][i] = 1;
    // for(int i = 2; i <= n; i+=2) w[i][1] = 1;
    // w[2][2] = 2;
    // for(int i = 2; i <= n; i++){
    //     for(int j = 2; j <= n; j++){
    //         if(i == 2 and j == 2) continue;
    //         w[i][j] = w[1][i] + w[i][j - 1] + w[i - 1][j] + w[j][1];
    //     }
    // }

    // cout << w[x][y] << ENDL;
    dp[0][0] = 1;  
    dp[1][0] = 1;  


    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            // Base cases
            if (i == 0 && j == 0) {
                dp[i][j] = 1;  // Empty board
            } else if (i == 1 && j == 0) {
                dp[i][j] = 1;  // One row, no columns, horizontal dominoes
            } else {
                // Horizontal dominoes
                if (j >= 2) {
                    dp[i][j] += dp[i][j - 2];
                }
                // Vertical dominoes
                if (i >= 2) {
                    dp[i][j] += dp[i - 2][j];
                }
            }
        }
    }

    cout << dp[y][x];
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}