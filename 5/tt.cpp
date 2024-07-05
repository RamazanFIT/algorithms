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
    int x = multi(a, b / 2) % mod;
    // x += mod;
    // x %= mod;
    if(b % 2 == 0) return (x % mod + x % mod) % mod;
    return (x % mod + x % mod + a % mod) % mod;
}
vii a;
int x = 1;
void rec(map<int, int>& mapa, int ii, int res){
    if(ii >= a.size()){
        // x *= res;
        // cout << res << " ";
        x = multi(x, res);
        return;
    }
    int p = 1;
    for(int i = 0; i <= mapa[a[ii]]; i++){
        rec(mapa, ii + 1, multi(res, p));
        // p *= a[ii];
        p = multi(p, a[ii]);
    }

}

int binpow(int a, int p){
    if(p == 0) return 1 % mod;
    if(p == 1) return a % mod;
    int x = binpow(a, p / 2);
    if(p % 2 == 0) return multi(x, x) % mod;
    return multi(multi(x, x), a) % mod;
}

void solve(int ccase){
    int n;cin>>n;
    vector<int> massive(n);
    int some = 1;
    map<int, int> mapa;
    set<int> st;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
        mapa[massive[i]]++;
        st.insert(massive[i]);

    }

    // if(n == 1){
    //     cout << massive[0];
    //     return;
    // }

    // vector<pair<int, int>> v;
    // v.pb({1, 0});

    // for(auto it : mapa){

    //     v.pb({it.first, it.second});
    
    // }
    // v.pb({1, 0});

    // for(int j = 1; j < v.size() - 1; j++){
    //     int a = 1;
    //     int b = 1;
    //     int dd = 1;
    //     for(int i = 0; i < v[j].ss; i++){
    //         // dd *= v[j].ff;
    //         // a *= dd;

    //         dd = multi(dd, v[j].ff);
    //         a = multi(a, dd);
    //     }
    //     dd = ((v[j].ff + 1) * 2) / 2;
    //     a = binpow(v[j].ff, dd);

    //     for(int i = 0; i < v[j].ss + 1; i++){

    //         // b *= v[j - 1].first;

    //         b = multi(b, v[j - 1].first);
    //     }
    //     int c = 1;
    //     for(int i = 0; i < v[j - 1].ss + 1; i++){
    //         // c *= a;
    //         c = multi(c, a);
    //         // cout << c << " ";
    //         // cout << v[j - 1].ss + 1 << " ";
    //     }

    //     // int ans = c * b;

    //     // v[j].first = ans;

    //     v[j].first = multi(c, b) % mod;
    //     // cout << v[j].first << " ";
    //     // cout << c << " " << b << ENDL;

    // }


    // cout << v[mapa.size()].first % mod;


    
    // for()

    // cout << res;


    for(auto it : st){
        a.pb(it);
    }
    rec(mapa, 0, 1);
    cout << x;
    

    // for(auto it : mapa){
    //     int k = it.first;
    //     for(int i = 0; i < it.second; i++){
    //         k *= it.first;
    //         // x *= k;
    //         x = x * pow(k, mapa.size());
    //     }
    //     x *= it.first;
    // }
    // cout << x % mod;
    


    // cout << rec(mapa, 0, 1);


    // int res = 1;
    
    // for(auto it : mapa){
    //     int k = 1;
    //     for(int i = 0 ; i <= it.second; i++){
    //         k *= it.first;
    //     }
    //     res *= k;
    // }
    // cout << res;
    
    
    // if(sq * sq == some){
    //     ans = multi(ans, sq);
    //                 ans += mod;
    //         ans %= mod;
    //     // cout << sq << " ";
    // }            ans += mod;
    //         ans %= mod;

    // cout << ans % mod << ENDL;

    // cout << multi(13, 10);
    
    

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