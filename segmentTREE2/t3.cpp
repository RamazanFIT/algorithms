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
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> t, d;

int L(int x){
    return 2 * x + 1;
}

int R(int x){
    return L(x) + 1;
}

void push(int x, int lx, int rx){
    if(d[x] != 0){
        int xm = (lx + rx) / 2;
        t[L(x)] += d[x] * (xm - lx);
        t[R(x)] += d[x] * (rx - xm);
        d[L(x)] += d[x];
        d[R(x)] += d[x];
        d[x] = 0;
    }
}

void change(int l, int r, int v, int x, int lx, int rx){

    if(lx >= r or rx <= l) return;

    if(lx >= l and rx <= r){
        t[x] += v * (rx - lx);
        d[x] += v;
        return;
    }
    push(x, lx, rx);
    int mm = (lx + rx) / 2;
    change(l, r, v, L(x), lx, mm);
    change(l, r, v, R(x), mm, rx);
    t[x] = t[L(x)] + t[R(x)];
}

int get(int l, int r, int x, int lx, int rx){
    
    if(lx >= r or rx <= l) return 0;
    if(lx >= l and rx <= r){
        return t[x];
    }
    push(x, lx, rx);
    int mm = (lx + rx) / 2;
    return get(l, r, L(x), lx, mm) + get(l, r, R(x), mm, rx);
}

void printTree(int x, int maxn, int tab){
    if(x >= maxn) return;
    printTree(R(x), maxn, tab + 4);
    repeat(tab) cout << "| "; cout << "(" <<  x << "," << t[x] << ")" << ENDL;
    printTree(L(x), maxn, tab + 4);
}

void solve(int ccase){


    int n;
    cin >> n;
    int q;
    cin >> q;

   
    d = t = vector<int>(4 * (n + 1));
    

    while(q--){
        int type;
        cin >> type;


        if(type == 0){
            int l, r, v;

            cin >> l >> r >> v;

            change(l - 1, r, v, 0, 0, n);
        } else{
            int l, r;

            cin >> l >> r;
            cout << get(l - 1, r, 0, 0, n) << ENDL;
        }
        printTree(0, 4 * (n + 1), 0);
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