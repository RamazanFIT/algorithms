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
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;

using ll = long long;
using namespace std;

vii d, t;
#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr 

void push(int x, int xl, int xr){
    
    if(d[x] != 0){
        d[R] += d[x];
        d[L] += d[x];
        t[R] += (xr - M) * d[x];
        t[L] += (M - xl) * d[x];
        d[x] = 0;
    }
}

void change(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l){
        return;
    }
    if(xl >= l and xr <= r){
        t[x] += v * (xr - xl);
        d[x] += v;
        return;
    }
    push(x, xl, xr);
    change(l, r, v, L, LL);
    change(l, r, v, R, RR);
    t[x] = t[L] + t[R];
}


int getSum(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l){
        return 0;
    }
    if(xl >= l and xr <= r){
        return t[x];
    }
    push(x, xl, xr);
    return getSum(l, r, L, LL) + getSum(l, r, R, RR);
}

void solve(int ccase){
    int n, q;cin>>n>>q;
    d = t = vii(4 * (n + 1));

    repeat(q){
        char a;
        cin >> a;
        int l, r;

        if(a == 'A'){
            cin >> l >> r;
            int x;
            cin >> x;
            change(l, r + 1, x, 0, 0, n);
            
        } else{
            int x;
            cin >> x;
            cout << getSum(x, x + 1, 0, 0, n) << ENDL;
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