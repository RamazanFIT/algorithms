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
vii t1, d1;
vii t2, d2;

vii massive1, massive2;

int L(int x) {return x * 2 + 1;}
int R(int x) {return L(x) + 1;}



#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr 

void build1(int x, int xl, int xr){
    if(xr - xl == 1){
        t1[x] = massive1[xl];
        return;
    } 
    build1(L(x),LL);
    build1(R(x),RR);

    t1[x] = t1[L(x)] + t1[R(x)];

}

void build2(int x, int xl, int xr){
    if(xr - xl == 1){
        t2[x] = massive2[xl];
        return;
    } 
    build2(L(x),LL);
    build2(R(x),RR);

    t2[x] = t2[L(x)] + t2[R(x)];

}


void push1(int x, int xl, int xr){
    if(d1[x] != -1){
        int xm = (xl + xr) / 2;

        t1[L(x)] = d1[x] * (xm - xl);
        t1[R(x)] = d1[x] * (xr - xm);
        d1[L(x)] = d1[x];
        d1[R(x)] = d1[x];
        d1[x] = -1;
    }
}

void change1(int l, int r, int v, int x, int xl, int xr){
    if(xr <= l or xl >= r) return;
    if(xl >= l and xr <= r){
        // t1[x] = v * (xr - xl);
        // d1[x] = v;

        if(t1[x] < 0){
            t1[x] = -v;
        } else{
            t1[x] = v;
        }
        // t1[x] = v;

        return;
    }
    // push1(x, xl, xr);
    int xm = (xl + xr) / 2;
    change1(l, r, v, L(x), xl, xm);
    change1(l, r, v, R(x), xm, xr);
    t1[x] = t1[L(x)] + t1[R(x)];
}

int get1(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;
    if(xl >= l and xr <= r){
        return t1[x];
    }
    // push1(x, xl, xr);
    int xm = (xl + xr) / 2;

    return get1(l, r, L(x), xl, xm) + get1(l, r, R(x), xm, xr);
}


void push2(int x, int xl, int xr){
    if(d2[x] != -1){
        int xm = (xl + xr) / 2;

        t2[L(x)] = d2[x] * (xm - xl);
        t2[R(x)] = d2[x] * (xr - xm);
        d2[L(x)] = d2[x];
        d2[R(x)] = d2[x];
        d2[x] = -1;
    }
}

void change2(int l, int r, int v, int x, int xl, int xr){
    if(xr <= l or xl >= r) return;
    if(xl >= l and xr <= r){
        t2[x] = v * (xr - xl);
        d2[x] = v;
        return;
    }
    push2(x, xl, xr);
    int xm = (xl + xr) / 2;
    change2(l, r, v, L(x), xl, xm);
    change2(l, r, v, R(x), xm, xr);
    t2[x] = t2[L(x)] + t2[R(x)];
}

int get2(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;
    if(xl >= l and xr <= r){
        return t2[x];
    }
    push2(x, xl, xr);
    int xm = (xl + xr) / 2;

    return get2(l, r, L(x), xl, xm) + get2(l, r, R(x), xm, xr);
}

void solve(int ccase){
    int n, q;cin >> n;
    t1 = vii(4 * (n +1));
    d1 = vii(4 * (n +1), -1);
    t2 = vii(4 * (n +1));
    d2 = vii(4 * (n +1), -1);

    massive1 = vii(n);
    massive2 = vii(n);

    repeat(n){
        // if(_ % 2 == 0){
        //     cin >> massive1[_];
        // } else{
        //     cin >> massive2[_];
        // }
        cin >> massive1[_];
        if(_ % 2 == 0) massive1[_] *= -1;
    }
    build1(0, 0, n);
    // build2(0, 0, n);
    cin >> q;
    repeat(q){
        // char a;
        // cin >> a;
        // if(a == 'A'){
        //     int l, r, v;cin>>l>>r>>v;
        //     change1(l - 1, r, v, 0, 0, n);
        // } else{
        //     int l, r;cin>>l>>r;
        //     cout << get1(l - 1, r, 0, 0, n) << ENDL;
        // }    

        int type;
        cin >> type;

        int l, r;
        cin >> l >> r;

        if(type == 0){
            change1(l - 1, l, r, 0, 0, n);
        } else{
            if(l % 2 == 0){
                cout << get1(l-1, r, 0, 0, n) << ENDL;
            } else{
                cout << -get1(l-1, r, 0, 0, n) << ENDL;

            }
        } 

        // if(type == 0){
        //     if(l % 2 == 0){
        //         change1(l - 1, l, r, 0, 0, n);
        //     } else{
        //         change2(l - 1, l, r, 0, 0, n);

        //     }
        // } else{
        //     if(l % 2 == 0){
        //         cout << -get1(l - 1, r, 0, 0, n) + get2(l - 1, r, 0, 0, n) << ENDL;
        //     } else{
        //         cout << get1(l - 1, r, 0, 0, n) - get2(l - 1, r, 0, 0, n) << ENDL;

        //     }
        // }


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