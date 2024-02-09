#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int ___ = 0; ___ < x; ___++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> t, massive;

int getLeft(int x) {return x * 2 + 1;}
int getRight(int x) {return (getLeft(x) + 1);}

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    } 
    int xm = (xl + xr) / 2;
    build(getLeft(x), xl, xm);
    build(getRight(x), xm, xr);
    t[x] = t[getLeft(x)] + t[getRight(x)];
}

void push(int x){
    if(t[x] != 0){
        t[getLeft(x)] = max(t[getLeft(x)], t[x]);
        t[getRight(x)] = max(t[getRight(x)], t[x]);
        t[x] = 0;
    }
}

void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r || xr <= l) return;
    if(xl >= l and xr <= r) {t[x] = max(t[x], v); return;}
    push(x);
    int xm = (xl + xr) / 2;
    change(l, r, v, getLeft(x), xl, xm);
    change(l, r, v, getRight(x), xm, xr);
}

int get(int i, int x, int xl, int xr){
    if(xr - xl == 1){
        return t[x];
    }           
    push(x);
    int xm = (xl + xr) / 2;
    if(i < xm) return get(i, getLeft(x), xl, xm);
    return get(i, getRight(x), xm, xr);

}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    t = vector<int>(4 * (n + 1));
    // massive = vector<int>(n);
    // for(int i = 0; i < n; i++){
    //     cin >> massive[i];
    // }
    // build(0, 0, n);
    repeat(q){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            change(l, r, v, 0, 0, n);
        } else{
            int i;
            cin >> i;
            cout << get(i, 0, 0, n) << ENDL;
        }
    }

    


    endd
}