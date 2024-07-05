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
using namespace std;
vector<int> d, massive;


vector<pair<int, int>> t;

int getLeft(int x) {return x * 2 + 1;}
int getRight(int x) {return getLeft(x) + 1;}

#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr 

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x].first = massive[xl];
        t[x].second = xl;
        return;
    }
    build(L, LL);
    build(R, RR);

    // t[x] = max(t[L], t[R]);
    if(t[L].first >= t[R].first){
        t[x] = t[L];
    } else{
        t[x] = t[R];
    }
}


void push(int x){
    if(d[x] != -1){
        t[getLeft(x)].first = d[x];
        d[getLeft(x)] = d[x];

        t[getRight(x)].first = d[x];
        d[getRight(x)] = d[x];

        d[x] = -1;
    }
}

void change(int l, int r, int v, int x, int xl, int xr){
    if(xl >= r or xr <= l){
        return;
    }
    if(xl >= l and xr <= r){
        t[x].first = v;
        d[x] = v;
        return;
    }
    push(x);
    int xm = (xl + xr) / 2;
    change(l, r, v, getLeft(x), xl, xm);
    change(l, r, v, getRight(x), xm, xr);

    // t[x] = max(t[getLeft(x)], t[getRight(x)]);
    if(t[getLeft(x)].first >= t[getRight(x)].first){
        t[x] = t[getLeft(x)];
    } else{
        t[x] = t[getRight(x)];
    }

}

pair<int, int> get(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l){
        return {INT_MIN, -1};
    }
    if(xl >= l and xr <= r) return t[x];
    push(x);
    int xm = (xr + xl) / 2;
    // return max(get(l, r, getLeft(x), xl, xm), get(l, r, getRight(x), xm, xr));
    pair<int, int> w1, w2;
    w1 = get(l, r, getLeft(x), xl, xm);
    w2 = get(l, r, getRight(x), xm, xr);


    if(w1.first >= w2.first){
        return w1;
    } else{
        return w2;
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int q;
    t = vector<pair<int, int>>(4 * (n + 1), {INT_MIN, -1});
    d = vector<int>(4 * (n + 1), -1);
    massive = vector<int>(n);
    
    repeat(n) cin >> massive[_];

    build(0, 0, n);

    cin >> q;
    repeat(q){
        char type;
        cin >> type;
            // pair<int, int> p;z
        if(type == 'b'){
            int l, v;cin >> l >> v;


            pair<int, int> p = get(l - 1, l, 0, 0, n);

            if(p.first > 0){
                change(l - 1, l, v, 0, 0, n);

            }

        } else{
            int l, r;
            cin >> l >> r;

            pair<int, int> p = get(l - 1, r, 0, 0, n);

            if(p.first > 0 and (p.ss != -1)){
                    cout << p.first << ENDL;
                    change(p.ss, p.ss + 1, 0, 0, 0, n);
            } else{
                pair<int, int> p1 = get(0, n, 0, 0, n);

                    if(p1.first > 0 and (p1.ss != -1)){
                        cout << p1.first << ENDL;
                        change(p1.ss, p1.ss + 1, 0, 0, 0, n);
                    } else{
                        cout << "O-o-ops" << ENDL;
                    }
            }
            
        }

    }
    
    


    endd
}