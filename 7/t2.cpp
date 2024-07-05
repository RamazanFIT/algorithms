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
// #define int ll
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
template<typename T>
void get(T &a) {std::cin >> a;}
template<typename T, typename... Args>
void get(T &a, Args&... args) {std::cin >> a;get(args...);}
template<typename T>
void put(const T &a) {std::cout << a;}
template<typename T, typename... Args>
void put(const T &a, const Args&... args) {std::cout << a;put(args...);}

using ll = long long;
using namespace std;

void solve(int ccase){
    int n, k;
    cin >> n >> k;

    vii massive(n);

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 2000000));
    repeat(n){
        cin >> massive[_];
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    sort(all(massive));
    // for(int i = 0; i <= k; i++){
    //     dp[0][i] = 0;
    // }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int cost = massive[i - 1];
            if(cost <= j){
                // dp[][] = min(dp[])
                int a, b;
                a = dp[i][j - cost] + 1;
                b = dp[i - 1][j];
                dp[i][j] = min(a, b);
            } else{
                int b = dp[i - 1][j];
                dp[i][j] = b;
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << ENDL;
    // }

    // cout << dp[n][k];
    int ans = dp[n][k];

    if(ans != 2000000){
        cout << ans;
    } else{
        cout << -1;
    }

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