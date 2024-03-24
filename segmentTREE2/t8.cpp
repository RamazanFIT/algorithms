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
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr 

vector<vector<int>> t;
vii massive;

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x].pb(massive[xl]);
        return;
    }
    build(L, LL);
    build(R, RR);
    merge(all(t[L]), all(t[R]), back_insert_iterator(t[x]));
}

int getans(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){
        // return (lower_bound(all(t[x]), v) - t[x].begin());
        return distance(t[x].begin(), lower_bound(all(t[x]), v));
    }
    return getans(l, r, v, L, LL) + getans(l, r, v, R, RR);
}

void solve(int ccase){
    int n; get(n);
    massive = vii(n);
    repeat(n) get(massive[_]);
    t = vvi(4 * (n + 1));
    build(0, 0, n);
    int q;get(q);
    repeat(q){
        int l, r, v;get(l, r, v);
        put(getans(l - 1, r, v, 0, 0, n), ENDL);
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