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
vector<int> massive;

int getLeft(int x){
    return x * 2 + 1;
}

int getRight(int x) { return x * 2 + 2;}

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

void seT(int i, int v, int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = v;
        return;
    }
    int xm = (xl + xr) / 2;
    if(i < xm) seT(i, v, getLeft(x), xl, xm);
    else seT(i, v, getRight(x), xm, xr);
    t[x] = t[getLeft(x)] + t[getRight(x)];
}

int get(int l, int r, int x, int xl, int xr){
    if(xl >= r || xr <= l){
        return 0;
    } 
    if(xl >= l and xr <= r){
        return t[x];
    }
    int xm = (xl + xr) / 2;
    return get(l, r, getLeft(x), xl, xm) + get(l, r, getRight(x), xm, xr);
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
    massive = vector<int>(n);
    repeat(q){
        char type;
        int l, r;
        cin >> type >> l >> r;
        if(type == 'A'){
            seT(l - 1, r, 0, 0, n);
        } else{
            cout << get(l - 1, r, 0, 0, n) << ENDL;
        }
    }





    endd
}