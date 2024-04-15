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


#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr

vector<pair<int, int>> t;
vii massive;

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = {massive[xl], xl};
        return;
    }
    build(L, LL);
    build(R, RR);

    if(t[L].ff > t[R].ff){
        t[x] = t[R];
    } else{
        t[x] = t[L];
    }
}

pair<int, int> get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return {INT_MAX, INT_MAX};

    if(xl >= l and xr <= r){
        return t[x];
    }
    pair<int, int> a, b;
    a = get(l, r, L, LL);
    b = get(l, r, R, RR);

    if(a.ff > b.ff){
        return b;
    } else{
        return a;
    }
}

void solve(int ccase){
    int n, k;get(n, k);
    massive = vii(n);
    repeat(n) get(massive[_]);
    t = vector<pair<int, int>>(4 * (n + 1));
    vii dp(n + 1);
    build(0, 0, n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        l = max(0ll, i - k + 1);
        r = i + 1;
        pair<int, int> tmp = get(l, r, 0, 0, n);
        dp[tmp.ss]++;
        cnt += tmp.ff;
    }
    
    put(cnt, ENDL);
    for(int i = 0; i < n; i++){
        put(dp[i], " ");
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