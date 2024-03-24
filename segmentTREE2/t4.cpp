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
#define get(a) cin >> a;

using ll = long long;
using namespace std;

#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr

vii t, d;
int n, q;

void push(int xl, int xr, int x){
    if(d[x]){
        t[L] = (M - xl) - t[L];
        t[R] = (xr - M) - t[R];
        d[L] ^= d[x];
        d[R] ^= d[x];
        d[x] ^= 1;
    }
}
void change(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        
        d[x] ^= 1;
        t[x] = (xr - xl) - t[x];
        return;
    }
    push(xl, xr, x);
    change(l, r, L, LL);
    change(l, r, R, RR);
    t[x] = t[L] + t[R];
}

int getk(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){
        return t[x];
    }
    push(xl, xr, x);
    return getk(l, r, L, LL) +  getk(l, r, R, RR);
}

int getK(int x, int xl, int xr, int k){
    // int mid = getk(0, M, 0, 0, n);
    // if(xr - xl == 1){
    //     return xl;
    // } else if(k > mid){
    //     return getK(R, RR, k);
    // } else{
    //     return getK(L, LL, k);
    // }
    if(xr - xl == 1) return xl;
    push(xl, xr, x);
    if(k > t[L]) return getK(R, RR, k - t[L]);
    else return getK(L, LL, k);
}

void printTree(int x, int maxn, int tab){
    if(x >= maxn) return;
    printTree(R, maxn, tab + 4);
    cout << string(tab, '|') << t[x] << " " << d[x] << ENDL;
    printTree(L, maxn, tab + 4);
}

void solve(int ccase){

    cin >> n >> q;
    t = d = vii(4 * (n + 1));


    repeat(q){
        int type;get(type)
        if(type == 1){
            int l, r;
            cin >> l >> r;
            change(l, r, 0, 0, n);
        } else{
            int k;
            cin >> k;
            cout << getK(0, 0, n, k + 1) << ENDL;
        }
        // printTree(0, 4 * (n + 1), 0);
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