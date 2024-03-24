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
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vii t, d;
vii massive;
int L(int x) {return x * 2 + 1;}
int R(int x) {return L(x) + 1;}

#define MID (xl + xr) / 2
#define LL xl, MID
#define RR MID, xr 


void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    } 
    build(L(x), LL);
    build(R(x), RR);
    // t[x] = t[R(x)] + t[L(x)];
    t[x] = gcd(t[R(x)], t[L(x)]);
}

void push(int x, int xl, int xr){
    if(d[x] != -1){
        int xm = (xl + xr) / 2;

        // t[L(x)] = d[x] * (xm - xl);
        // t[R(x)] = d[x] * (xr - xm);
        // d[L(x)] = d[x];
        // d[R(x)] = d[x];
        // d[x] = -1;
        
    }
}

void change(int l, int r, int v, int x, int xl, int xr){
    if(xr <= l or xl >= r) return;
    if(xl >= l and xr <= r){
        t[x] = v * (xr - xl);
        d[x] = v;
        return;
    }
    push(x, xl, xr);
    int xm = (xl + xr) / 2;
    change(l, r, v, L(x), xl, xm);
    change(l, r, v, R(x), xm, xr);
    t[x] = t[L(x)] + t[R(x)];
}

int get(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;
    if(xl >= l and xr <= r){
        return t[x];
    }
    push(x, xl, xr);
    int xm = (xl + xr) / 2;

    return get(l, r, L(x), xl, xm) + get(l, r, R(x), xm, xr);
}
void solve(int ccase){
    int n, q;cin >> n >> q;
    t = vii(4 * (n +1));
    d = vii(4 * (n +1), -1);

    repeat(q){
        char a;
        cin >> a;
        if(a == 'A'){
            int l, r, v;cin>>l>>r>>v;
            change(l - 1, r, v, 0, 0, n);
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