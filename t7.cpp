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
inline vector<int> t, d;
int neutral;

inline int getLeft(int x) {return 2 * x + 1;}
inline int getRight(int x) {return getLeft(x) + 1;}

inline void push(int x){
    if(d[x] != 0){
        t[getLeft(x)] = (t[getLeft(x)] | d[x]);
        d[getLeft(x)] = (d[getLeft(x)] | d[x]);

        t[getRight(x)] = (t[getRight(x)] | d[x]);
        d[getRight(x)] = (d[getRight(x)] | d[x]);

        d[x] = 0;
    }
}
inline void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r) {
        t[x] = (t[x] | v);
        d[x] = (d[x] | v);
        return;
    }
    push(x);
    int xm = (xr + xl) / 2;
    change(l, r, v, getLeft(x), xl, xm);
    change(l, r, v, getRight(x), xm, xr);
    t[x] = (t[getLeft(x)] & t[getRight(x)]);
}


inline int get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return INT_MAX;
    if(xl >= l and xr <= r) {
        return t[x];
    }
    push(x);
    int xm = (xl + xr) / 2;
    return (get(l, r, getLeft(x), xl, xm) & get(l, r, getRight(x), xm, xr));
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // int x = 1;
    // for(int i = 0; i < 33; i++){
    //     neutral += x;
    //     x *= 2;
    // }
    int n;
    cin >> n;
    int q;
    cin >> q;
    t = vector<int>(4 * (n + 1));
    d = vector<int>(4 * (n + 1));

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