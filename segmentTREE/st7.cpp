// Bismillah 
// لا إله إلا الله محمد رسول الله
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define int ll
#define vvi vector<vector<int>>
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> t, tt, d, dd, d2, dd2;
vector<int> mass;
vector<bool> isThat;
int n;
#define L 2 * x + 1
#define R 2 * x + 2
#define MID (xl + xr) / 2
#define LL xl, MID
#define RR MID, xr 
#define INF LLONG_MAX / 4



void build1(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = mass[xl];
        return;
    }
    build1(L, LL);
    build1(R, RR);
    t[x] = t[L] + t[R];
}

void push1(int x, int xl, int xr){
    if(d[x] != INF){
        t[L] = d[x] * (MID - xl);
        t[R] = d[x] * (xr - MID);
        d[L] = d[x];
        d[R] = d[x];
        dd[L] = 0;
        dd[R] = 0;
        d[x] = INF;
    }

    if(dd[x] != 0){
        t[L] += dd[x] * (MID - xl);
        t[R] += dd[x] * (xr - MID);
        dd[L] += dd[x];
        dd[R] += dd[x];
        dd[x] = 0;
    }
    
}

void setting1(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] = (xr - xl) * v;
        d[x] = v;
        dd[x] = 0;
        return;
    }
    push1(x, xl, xr);
    setting1(l, r, v, L, LL);
    setting1(l, r, v, R, RR);
    t[x] = t[L] + t[R];
}



void change1(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] += v * (xr - xl);
        dd[x] += v;
        return;
    }
    push1(x, xl, xr);
    change1(l, r, v, L, LL);
    change1(l, r, v, R, RR);
    t[x] = t[L] + t[R];
}

int get1(int l, int r, int x, int xl, int xr){

    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){

        return t[x];
    }
    push1(x, xl, xr);
    return get1(l, r, L, LL) + get1(l, r, R, RR);
}

void build2(int x, int xl, int xr){
    if(xr - xl == 1){
        tt[x] = mass[xl] * mass[xl];
        return;
    }
    build2(L, LL);
    build2(R, RR);
    
    tt[x] = tt[L] + tt[R];
}

void push2(int x, int xl, int xr){
    if(d2[x] != INF){
        tt[L] = d2[x] * d2[x] * (MID - xl);
        tt[R] = d2[x] * d2[x] * (xr - MID);
        d2[L] = d2[x];
        d2[R] = d2[x];
        dd2[L] = 0;
        dd2[R] = 0;
        d2[x] = INF;
    }

    if(dd2[x] != 0){
        tt[L] += -dd2[x] * dd2[x] * (MID - xl) + 2 * dd2[x] * get1(xl, MID, 0, 0, n);
        tt[R] += -dd2[x] * dd2[x] * (xr - MID) + 2 * dd2[x] * get1(MID, xr, 0, 0, n);

        dd2[L] += dd2[x];
        dd2[R] += dd2[x];
        dd2[x] = 0;
    }
    
}

void setting2(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        tt[x] = (xr - xl) * v * v;
        d2[x] = v;
        dd2[x] = 0;
        return;
    }
    push2(x, xl, xr);
    setting2(l, r, v, L, LL);
    setting2(l, r, v, R, RR);
    tt[x] = tt[L] + tt[R];
}

void change2(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        tt[x] += v * v * (xr - xl) + 2 * v * get1(xl, xr, 0, 0, n);
        dd2[x] += v;
        return;
    }
    push2(x, xl, xr);
    change2(l, r, v, L, LL);
    change2(l, r, v, R, RR);
    tt[x] = tt[L] + tt[R];
}

int get2(int l, int r, int x, int xl, int xr){

    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){
        return tt[x];
    }
    push2(x, xl, xr);
    return get2(l, r, L, LL) + get2(l, r, R, RR);
}





void solve(int ccase){
    cout << "Case " << ccase + 1 << ":" << ENDL;
    int q;cin>>n >> q;
    mass = vii(n, 0);
    dd2 = dd = t = tt = vii(4 * (n + 1), 0);
    d = d2 = vii(4 * (n + 1), INF);
    repeat(n) cin >> mass[_];
    build1(0, 0, n);
    build2(0, 0, n);

    repeat(q){
        int a;
        cin >> a;
        if(a == 1){
            int l, r, v;cin>>l>>r>>v;
            change2(l - 1, r, v, 0, 0, n);
            change1(l - 1, r, v, 0, 0, n);

        } else if(a == 0){
            int l, r, v;cin>>l>>r>>v;
            setting1(l - 1, r, v, 0, 0, n);
            setting2(l - 1, r, v, 0, 0, n);
        } else{
            int l, r;cin>>l>>r;
            cout << get2(l - 1, r, 0, 0, n) << ENDL;
        }
        
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}