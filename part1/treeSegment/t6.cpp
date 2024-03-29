#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> t, d;
int mod = 1e9 + 7;
int getLeft(int x) {return 2 * x + 1;}
int getRight(int x) {return getLeft(x) + 1;}

void push(int x){
    if(d[x] != 1){
        t[getLeft(x)] = ((t[getLeft(x)] % mod) * (d[x] % mod)) % mod;
        d[getLeft(x)] = ((d[getLeft(x)] % mod) * (d[x] % mod)) % mod;

        t[getRight(x)] = ((t[getRight(x)] % mod) * (d[x] % mod)) % mod;
        d[getRight(x)] = ((d[getRight(x)] % mod) * (d[x] % mod)) % mod;

        d[x] = 1;
    }   
}
void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] = ((t[x] % mod) * (v % mod)) % mod;
        d[x] = ((d[x] % mod) * (v % mod)) % mod;
        return;
    }
    push(x);
    int xm = (xl + xr) / 2;
    change(l, r, v, getLeft(x), xl, xm);
    change(l, r, v, getRight(x), xm, xr);
    t[x] = (t[getLeft(x)] % mod + t[getRight(x)] % mod) % mod;
}

int get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return 0;
    if(xl >= l and xr <= r){
        return t[x] % mod;
    }
    push(x);
    int xm = (xl + xr) / 2;
    return (get(l, r, getLeft(x), xl, xm) % mod + get(l, r, getRight(x), xm, xr) % mod) % mod;
}

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = 1;
        return;
    }
    int xm = (xl + xr) / 2;
    build(getLeft(x), xl, xm);
    build(getRight(x), xm, xr);
    t[x] = (t[getLeft(x)] % mod + t[getRight(x)] % mod) % mod;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int q;
    cin >> q;
    t = vector<int>(4 * (n + 1));
    d = vector<int>(4 * (n + 1), 1);
    build(0, 0, n);
    repeat(q){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            change(l, r, v, 0, 0, n);
        } else{
            int l, r;
            cin >> l >> r;
            cout << get(l, r, 0, 0, n) << ENDL;
        }
    }
    
    endd
}