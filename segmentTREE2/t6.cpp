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

vector<set<int>> t;
vii d;

void push(int xl, int xr, int x){
    if(d[x] != 0){
        set<int> tmp1;
        set<int> tmp2;
        
        for(auto it : t[L]){
            tmp1.insert(d[x] + it);
        }
        for(auto it : t[R]){
            tmp2.insert(d[x] + it);
        }
        t[L] = tmp1;
        t[R] = tmp2;
        d[L] = d[x];
        d[R] = d[x];
        d[x] = 0;
    }
}

void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;

    if(xl >= l and xr <= r){
        set<int> tmp;
        for(auto it : t[x]){
            tmp.insert(it + v);
        }
        t[x] = tmp;
        d[x] = v;
        return;
    }
    push(xl, xr, x);
    change(l, r, v, L, LL);
    change(l, r, v, R, RR);
    t[x].clear();
    for(auto it : t[L]){
        t[x].insert(it);
    }
    for(auto it : t[R]){
        t[x].insert(it);
    }
}

int getans(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return -1;
    // if(xl >= l and xr <= r){
    //     if(t[L].lower_bound(v) != t[L].end()){
    //         return distance(t[L].begin(), t[L].lower_bound(v)) + xl;
    //     } 
    //     if(t[R].lower_bound(v) != t[R].end()){
    //         return distance(t[R].begin(), t[R].lower_bound(v)) + xl;
    //     } else{
    //         return INT_MAX;
    //     }
    // }
    // push(xl, xr, x);
    // return min(getans(l, r, v, L, LL), getans(l, r, v, R, RR));
    if(xr - xl == 1){
        return xl;
    }
    push(xl, xr, x);
    if(l >= xl and l < M){
        if(t[L].lower_bound(v) != t[L].end()){
            return getans(l, r, v, L, LL);
        }
    } else if(l >= M and l < xr){
        if(t[R].lower_bound(v) != t[R].end()){
            return getans(l, r, v, R, RR);
        }
    }

    return -1;
}

void printTree(int x, int maxn, int tab){
    if(x >= maxn) return;
    printTree(R, maxn, tab + 4);
    cout << string(tab, '|');
    for(auto it : t[x]) cout << it << " ";
    cout << ENDL;
    printTree(L, maxn, tab + 4);
}

void solve(int ccase){
    int n, q;
    cin >> n >> q;
    set<int> f;
    f.insert(0);
    t = vector<set<int>>(4 * (n + 1), f);
    d = vii(4 * (n + 1));
    
    repeat(q){
        int type;cin>>type;

        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            change(l, r, v, 0, 0, n);
        } else{
            int l, r;
            cin >> r >> l;
            cout << getans(l, n, r, 0, 0, n) << ENDL;
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