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

vector<int> t, d, massive;

#define L 2 * x + 1
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    }

    build(L, LL);
    build(R, RR);

    t[x] = t[L] + t[R];
}

void push(int x){
    if(d[x] != 0){
        d[L] += d[x];
        d[R] += d[x];
        t[L] += d[L];
        t[R] += d[R];
        d[x] = 0;
    }
}

void change(int l, int r, int x, int v, int xl, int xr){
    if(xr <= l or xl >= r) return;

    if(xl >= l and xr <= r){
        t[x] += v;
        d[x] += v;
        return;
    }
    push(x);

    change(l, r, L, v, LL);
    change(l, r, R, v, RR);

    t[x] = t[L] + t[R];
}

int getans(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;

    if(xl >= l and xr <= r){
        return t[x];
    }
    push(x);

    return getans(l, r, L, LL) + getans(l, r, R, RR);

    
}

void solve(int ccase){
    int n;
    cin >> n;
    int q;
    cin >> q;
    // vii massive(n);
    t = d = vii(4 * (n + 1));
    massive = vii(n);
    
    repeat(n) get(massive[_]);
    build(0, 0, n);
    repeat(q){
        int type;
        cin >> type;
        int l, r;get(l, r);
        if(type == 1){
            cout << getans(l, r, 0, 0, n) << ENDL;
        } else{
            change(l, l + 1, 0, r, 0, n);
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