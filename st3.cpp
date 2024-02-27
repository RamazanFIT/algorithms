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
#define R x * 2 + 2
#define L x * 2 + 1
#define MID (xl + xr) / 2
#define LEFT xl, MID
#define RIGHT MID, xr
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vii t, d;


void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = 1;
        return;
    } 
    build(L, LEFT);
    build(R, RIGHT);
    t[x] = t[R] + t[L];
}

void push(int x, int xl, int xr){
    if(d[x] != 0){
        // t[L] ^= d[x];
        // t[R] ^= d[x];
        t[L] = (MID - xl) - t[L];
        t[R] = (xr - MID) - t[R];
        d[L] ^= d[x];
        d[R] ^= d[x];
        d[x] = 0;
    } 
}
void change(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] = (xr - xl) - t[x];
        d[x] ^= 1;
        return;
    }
    push(x, xl, xr);
    change(l, r, L, LEFT);
    change(l, r, R, RIGHT);
    t[x] = t[L] + t[R];
}

int get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){
        return t[x];
    }
    push(x, xl, xr);
    return get(l, r, L, LEFT) + get(l, r, R, RIGHT);
}

void solve(int ccase){
    int n, q;cin>>n>>q;

    t = d = vii(4 * (n + 1));
    // build(0, 0, n);
    repeat(q){
        int a;
        cin >> a;
        int l, r;cin>>l>>r;
        if(a == 0){
            change(l - 1, r, 0, 0, n);
        } else{
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