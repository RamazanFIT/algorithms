#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> t;

void add(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r || xr <= l) return;
    if(xl >= l and xr <= r) {t[x] += v; return;}
    int xm = (xl + xr) / 2;
    add(l, r, v, x * 2 + 1, xl, xm);
    add(l, r, v, x * 2 + 2, xm, xr);
}

int get(int i, int x, int xl, int xr){
    if(xr - xl == 1){
        return t[x];
    }
    if(i < (xl + xr) / 2)  return get(i, x * 2 + 1, xl, (xl + xr) / 2) + t[x];
    return get(i, x * 2 + 2, (xl + xr) / 2, xr) + t[x]; 
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    t = vector<int>(4 * (n + 1));
    repeat(q){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            add(l, r, v, 0, 0, n);
        } else{
            int i;
            cin >> i;
            cout << get(i, 0, 0, n) << ENDL;
        }
    }
    endd
}