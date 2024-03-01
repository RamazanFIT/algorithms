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
#define int ll
vector<int> t, d, dd;
vector<int> mass;
vii jojo;
int T = 1;
#define L 2 * x + 1
#define R 2 * x + 2
#define MID (xl + xr) / 2
#define LL xl, MID
#define RR MID, xr 


void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = mass[xl];
        return;
    }
    build(L, LL);
    build(R, RR);
    t[x] = t[L] + t[R];
}


void push1(int x, int xl, int xr){
    if(d[x] != -1){
        t[L] = d[x] * (MID - xl);
        t[R] = d[x] * (xr - MID);
        d[L] = d[x];
        d[R] = d[x];
        dd[L] = 0;
        dd[R] = 0;
        d[x] = -1;
    }
}

void push2(int x, int xl, int xr){
    push1(x, xl, xr);

    if(dd[x] != 0){
        t[L] += dd[x] * (MID - xl);
        t[R] += dd[x] * (xr - MID);
        dd[L] += dd[x];
        dd[R] += dd[x];
        dd[x] = 0;
    }
    
}

void setting(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] = (xr - xl) * v;
        d[x] = v;
        dd[x] = 0;
        return;
    }
    push2(x, xl, xr);
    setting(l, r, v, L, LL);
    setting(l, r, v, R, RR);
    t[x] = t[L] + t[R];
}



void change(int l, int r, int v, int x, int xl, int xr){

    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] += v * (xr - xl);
        dd[x] += v;
        return;
    }
    push2(x, xl, xr);
    change(l, r, v, L, LL);
    change(l, r, v, R, RR);
    t[x] = t[L] + t[R];
}

int get(int l, int r, int x, int xl, int xr){

    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){

        return t[x];
    }
    push2(x, xl, xr);
    return get(l, r, L, LL) + get(l, r, R, RR);
}

void solve(int ccase){
    int n, q;cin>>n;
    mass = vii(n, 0);
    dd = t = vii(4 * (n + 1), 0);
    d = vii(4 * (n + 1), -1);
    jojo = vii(4 * (n + 1));
    repeat(n) cin >> mass[_];
    build(0, 0, n);

    cin >> q;
    
    repeat(q){
        int a;
        cin >> a;
        if(a == 1){
            int l, r, v;cin>>l>>r>>v;
            change(l - 1, r, v, 0, 0, n);
        } else if(a == 2){
            int l, r, v;cin>>l>>r>>v;
            setting(l - 1, r, v, 0, 0, n);
        } else{
            int l, r;cin>>l>>r;
            cout << get(l - 1, r, 0, 0, n) << ENDL;
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