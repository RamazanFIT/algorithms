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

vector<pair<int, int>> t;
vii massive;
#define L 2 * x + 1
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr


void build(int x, int xl, int xr){
    if(xr - xl == 1){

        t[x] = {massive[xl], 0};
        return;
    }

    build(L, LL);
    build(R, RR);

 
    int a = max(t[L].ff, t[L].ss);
    int b = max(t[R].ff, t[R].ss);

    int c = min(t[L].ff, t[L].ss);
    int d = min(t[R].ff, t[R].ss);

    int e = max(c, d);

    int k = max(a, b);

    t[x] = {k, a + b + e - k - min(e, min(a, b))};

    
}

void change(int l, int r, int x, int v, int xl, int xr){
    if(xr <= l or xl >= r){
        return;
    }

    if(xl >= l and xr <= r){
        t[x] = {v, 0};

        return;
    }
    change(l, r, L, v, LL);
    change(l, r, R, v, RR);
    int a = max(t[L].ff, t[L].ss);
    int b = max(t[R].ff, t[R].ss);

    int c = min(t[L].ff, t[L].ss);
    int d = min(t[R].ff, t[R].ss);

    int e = max(c, d);

    int k = max(a, max(b, e));


    t[x] = {k, a + b + e - k - min(e, min(a, b))};
    
}

pair<int, int> getans(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r){
        return {0, 0};
    }
    if(xl >= l and xr <= r){
        return t[x];
    }

    pair<int, int> aa, bb;
    aa = getans(l, r, L, LL);
    bb = getans(l, r, R, RR);

    int a = max(aa.ff, aa.ss);
    int b = max(bb.ff, bb.ss);

    int c = min(aa.ff, aa.ss);
    int d = min(bb.ff, bb.ss);

    int e = max(c, d);

    int k = max(a, max(b, e));

    return {k, a + b + e - k - min(e, min(a, b))};


}


void solve(int ccase){
    int n;get(n);

    // vector<int> massive(n);
    massive = vii(n);
    
    repeat(n){
        get(massive[_]);
    }

    t = vector<pair<int, int>>(4 * (n + 1), {0, 0});

    build(0, 0, n);

    int q;
    get(q);
    repeat(q){
        char a;
        cin >> a;
        int l, r;
        cin >> l >> r;

        if(a == 'Q'){
            pair<int, int> p = getans(l - 1, r, 0, 0, n);

            cout << p.first + p.second << ENDL;
            // cout << p.ff << " " << p.ss << ENDL;
        } else{
            change(l - 1, l, 0, r, 0, n);
        }
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