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
int mod = 1e9 + 7;
int multi(int a, int b){
    if(b == 0) return 0;
    if(b == 1) return a % mod;
    int x = multi(a, b / 2ll) % mod;
    x += mod;
    x %= mod;
    if(b % 2ll == 0) return (x % mod + x % mod) % mod;
    return (x % mod + x % mod + a % mod) % mod;
}


int binpow(int a, int p){
    if(p == 0) return 1ll % mod;
    if(p == 1) return a % mod;
    int x = binpow(a, p / 2ll) % mod;
    x += mod;
    x %= mod;
    if(p % 2 == 0) return (x % mod * x % mod) % mod;
    return ((x % mod * x % mod) * a % mod) % mod;
}

void solve(int ccase){

    // cout << binpow(2, mod - 2);
    int n;
    cin >> n;

    map<int, int> mapa;

    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        mapa[el]++;
    }

    int x = 1;
    int p = 1;
    int prev = 1;
    int ans = 1;
    for(auto it : mapa){
        int f1 = binpow(prev, it.second + 1ll);
        int f2 = ((((it.second) % mod * (it.second + 1ll) % mod) * p % mod) / 2);
        int f3 = it.first;
        ans = (f1 % mod * binpow(f3 % mod, f2 % mod));
        prev = ans;
        prev += mod;
        prev %= mod;
        x = it.first;
        p = it.second + 1;
    }
    cout << ans % mod;
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