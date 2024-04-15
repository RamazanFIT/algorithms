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
    int n, m;get(n, m);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    vector<vector<set<int>>> dppp(n + 1, vector<set<int>>(m + 1));
    vector<vector<int>> massive(n + 1, vector<int>(m + 1));

    for(int i = 0;i<n;i++){
        for(int j = 0; j<m;j++){
            cin >> massive[i][j];
        }
    }
    // dp[1][1] = massive[0][0];
    dp[1][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // dp[i][j] = max(gcd(dp[i - 1][j], massive[i - 1][j - 1]), gcd(dp[i][j - 1], massive[i - 1][j - 1]));
            // for(auto it : dppp[i - 1][j]){
            //     dp[i][j] = max(gcd(dp[i - 1][j], massive[i - 1][j - 1]), it);
            // }
            // for(auto it : dppp[i][j - 1]){
            //     dp[i][j] = max(gcd(dp[i][j -], massive[i - 1][j - 1]), it);
            // }
            dp[i][j] = max(gcd(dp[i - 1][j], massive[i - 1][j - 1]), gcd(dp[i][j - 1], massive[i - 1][j - 1]));
            int tmp = 1;
            for(auto it : dppp[i][j - 1]){
                int x = gcd(it, massive[i - 1][j - 1]);
                dppp[i][j].insert(x);
                tmp = max(tmp, x);
            }
            tmp = 1;
            for(auto it : dppp[i - 1][j]){
                int x = gcd(it, massive[i - 1][j - 1]);
                dppp[i][j].insert(x);
                tmp = max(tmp, x);
            }
            dp[i][j] = max(dp[i][j], tmp);
            dppp[i][j].insert(dp[i][j]);
            dppp[i][j].insert(gcd(dp[i - 1][j], massive[i - 1][j - 1]));dppp[i][j].insert(gcd(dp[i][j - 1], massive[i - 1][j - 1]));
        }
    }
    put(dp[n][m], ENDL);
    // for(int i = 0;i<n;i++){
    //     for(int j = 0; j<m;j++){
    //         // cin >> massive[i][j];
    //         cout << dp[i + 1][j + 1] << " ";
    //     } put(ENDL);
    // }
    // for(auto it : dppp[n][m]){
    //     put(it, " ");
    // }

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