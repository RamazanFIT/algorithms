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

vector<vector<int>> t;
vii massive;
#define L 2 * x + 1
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr


void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x].pb(massive[xl]);
        return;
    }

    build(L, LL);
    sort(all(t[L]));
    build(R, RR);
    sort(all(t[R]));

    int a, b;
    a = t[L].back();
    b = t[R].back();
    t[x].clear();
    t[x].pb(a);
    t[x].pb(b);
    sort(all(t[x]));
    for(auto it : t[x]){
        cout << it << " ";
    }cout << endl;
    
}

void change(int l, int r, int x, int v, int xl, int xr){
    if(xr <= l or xl >= r){
        return;
    }

    if(xl >= l and xr <= r){
        t[x].clear();
        t[x].pb(v);
        return;
    }
    change(l, r, L, v, LL);
    change(l, r, R, v, RR);
    int a, b;
    a = t[L].back();
    b = t[R].back();
    t[x].clear();

    t[x].pb(a);
    t[x].pb(b);
    sort(all(t[x]));
    
}

vii getans(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r){
        // return vii();
        vii tmp;
        tmp.pb(INT_MIN);
        return tmp;
    }
    if(xl >= l and xr <= r){
        return t[x];
    }

    vii a = getans(l, r, L, LL);
    vii b = getans(l, r, R, RR);
    sort(all(a));
    sort(all(b));
    vii tmp = {a.back(), b.back()};
    sort(all(tmp));

    return tmp;
    
}


void solve(int ccase){
    int n;get(n);

    // vector<int> massive(n);
    massive = vii(n);
    
    repeat(n){
        get(massive[_]);
    }

    t = vector<vector<int>>(4 * (n + 1));

    build(0, 0, n);

    // int q;
    // get(q);
    // repeat(q){
    //     char a;
    //     cin >> a;
    //     int l, r;
    //     cin >> l >> r;

    //     if(a == 'Q'){
    //         vii tmp = getans(l - 1, r, 0, 0, n);
            
    //         for(auto it : tmp){
    //             cout << it << " ";
    //         }

    //         // cout << tmp.front() + tmp.back() << ENDL;
    //     } else{
    //         change(l - 1, l + 1, 0, r, 0, n);
    //     }
    // }
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