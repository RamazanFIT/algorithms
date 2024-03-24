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

vii a, d, dl;

void push(int xl, int xr, int x){
    if(dl[x] + d[x] + a[x]){
        d[L] += d[x];
        d[R] += d[x];
        dl[L] += dl[x];
        dl[R] += dl[x];
        a[L] += a[x];
        a[R] += a[x];
        d[x] = 0;
        dl[x] = 0;
        a[x] = 0;
    }
}

void change(int l, int r, int aa, int dd, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;

    if(xl >= l and xr <= r){
        d[x] += dd;
        dl[x] += dd * l;
        a[x] += aa;
        return;
    }
    push(xl, xr, x);

    change(l, r, aa, dd, L, LL);
    change(l, r, aa, dd, R, RR);

}

int f(int a, int d, int i, int dl){
    return a + d * i - dl;
}

int getans(int i, int x, int xl, int xr){
    if(xr - xl == 1){
        return f(a[x], d[x], xl, dl[x]);
    }
    push(xl, xr, x);
    if(i < M){
        return getans(i, L, LL);
    } else{
        return getans(i, R, RR);
    }
}



void solve(int ccase){
    int n, q;get(n, q);
    
    a = d = dl = vii(4 * (n + 1));
    

    repeat(q){
        int type;get(type);
        if(type == 2){
            int i;get(i);
            put(getans(i - 1, 0, 0, n), ENDL);
        } else{
            int l, r, aa, dd;get(l, r, aa, dd);
            change(l - 1, r, aa, dd, 0, 0, n);
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