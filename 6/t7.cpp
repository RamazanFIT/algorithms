#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
#define int ll
using namespace std;
vector<int> t, d, massive;

int getLeft(int x) {return x * 2 + 1;}
int getRight(int x) {return getLeft(x) + 1;}


#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr 

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    }
    build(L, LL);
    build(R, RR);

    t[x] = min(t[L], t[R]);
}


void push(int x){
    if(d[x] != 0){
        t[getLeft(x)] = t[getLeft(x)] + d[x];
        d[getLeft(x)] = d[getLeft(x)] + d[x];

        t[getRight(x)] = t[getRight(x)] + d[x];
        d[getRight(x)] = d[getRight(x)] + d[x];

        d[x] = 0;
    }
}
void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        t[x] = t[x] + v;
        d[x] = d[x] + v;
        return;
    }
    push(x);
    int xm = (xl + xr) / 2;
    change(l, r, v, getLeft(x), xl, xm);
    change(l, r, v, getRight(x), xm, xr);
    t[x] = min(t[getLeft(x)], t[getRight(x)]);
}

int get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return LLONG_MAX;
    if(xl >= l and xr <= r) return t[x];
    push(x);
    int xm = (xl + xr) / 2;
    return min(get(l, r, getLeft(x), xl, xm), get(l, r, getRight(x), xm, xr));
}


void solve(int ccase){
    int n;
    cin >> n;
    int q;
    cin >> q;
    t = vector<int>(4 * (n + 1), INT_MAX);
    d = vector<int>(4 * (n + 1));
    massive = vector<int>(n);
    
    repeat(n) cin >> massive[_];

    build(0, 0, n);
    cout << "Case " << ccase + 1 << ":" << ENDL;
    repeat(q){
        // int type;
        // cin >> type;
        // if(type == 1){
        //     int l, r, v;
        //     cin >> l >> r >> v;
        //     change(l, r, v, 0, 0, n);
        // } else{
            int l, r;
            cin >> l >> r;
            cout << get(l - 1, r, 0, 0, n) << ENDL;
        // }
    }
}
signed main(){
    
    goodluck
    
    int t = 1;
    cin >> t;

    repeat(t){
        solve(_);
    }


    endd
}




