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

vii t, d;
int n, q;

#define L 2 * x + 1
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr 

void push(int xl, int xr, int x){
    if(d[x]){
        t[L] += d[x];
        t[R] += d[x];
        d[L] += d[x];
        d[R] += d[x];
        d[x] = 0;
    }
}

void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] += v;
        d[x] += v;
        return;
    }
    push(xl, xr, x);
    
    change(l, r, v, L, LL);
    change(l, r, v, R, RR);

    t[x] = max(t[L], t[R]);
}

int getans(int l, int v, int x, int xl, int xr){
    push(xl, xr, x);
    if(t[x] < v) return -1;
    if(t[x] >= v and xr - xl == 1) return xl;

    if(l < M){
        int ans1 = getans(l, v, L, LL);
        if(ans1 >= l) return ans1;
    }
    int ans2 = getans(l, v, R, RR);
    if(ans2 >= l) return ans2;
    return -1;
}

int get1(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return INT_MIN;
    
    if(xl >= l and xr <= r){
        return t[x];
    }
    push(xl, xr, x);
    
    return max(get1(l, r, L, LL), get1(l, r, R, RR));
}


void printTree(int x, int tab, int n){
    if(x >= 4 * n)  return;
    printTree(R, tab + 2, n);
    repeat(tab) put("| ");
    put(t[x], ENDL);
    printTree(L, tab + 2, n);
}

void solve(int ccase){

    get(n, q);
    t=d=vii(8 * (n + 1));
    repeat(q){
        int type;
        get(type);
        if(type == 1){
            int l, r, v;get(l, r, v);
            change(l, r, v, 0, 0, n);
        } else if(type == 2){
            int v, l;
            get(v, l);
            int ans = getans(l, v, 0, 0, n);
            if(ans >= l)
            put(ans, ENDL);
            else put(-1, ENDL);
        } else{
            int x;get(x);
            
            put("point: ", get1(x, x + 1, 0, 0, n), ENDL);
            // int l, r;get(l, r);
            // put("max: ", get1(l, r, 0, 0, n), ENDL);
        }
        // printTree(0, 0, n);
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