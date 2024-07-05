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

int rec(int n, int x){
    if(x > n) return 0;
    if(x == n) return 1;
    int sum = 0;
    for(int i = 1; i <= 6; i++){
        sum += rec(n, x + i);
    }

    return sum;
}
int mod = 1e9 + 7;

int binpow(int n, int p){
    if(p == 0) return 1;
    if(p == 1) return n % mod;

    int xx = binpow(n, p / 2) % mod;

    if(p % 2 == 0) return (xx * xx) % mod;

    return (xx * xx * n) % mod;
}

void solve(int ccase){
    int n;
    cin >> n;

    vii dp(n + 3);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for(int i = 7; i <= n; i++){
        // dp[i] = ((dp[i - 1] % mod) * 2) % mod - 1;
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod + dp[i - 4] % mod + dp[i - 5] % mod + dp[i - 6] % mod) % mod;
    }

    cout << dp[n];


    // if(n == 7) cout << 63;
    // else cout << 0;
    // cout << rec(n, 0);
    // int sum = 0;
    // for(int i = 1; i < 16; i++){
    //     cout << "For " << i << ": ";
    //     cout << rec(i, 0) << " ";
    //     sum += rec(i, 0);

    //     cout << sum << " " << ENDL;
    // }

    // // cout << binpow(2, n - 1);
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