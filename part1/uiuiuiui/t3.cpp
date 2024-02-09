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

vector<set<int>> t;
vector<int> massive;

int getLeft(int x){
    return x * 2 + 1;
}

int getRight(int x) { return x * 2 + 2;}

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x].insert(massive[xl]);
        return;
    }
    int xm = (xl + xr) / 2;
    
    build(getLeft(x), xl, xm);
    build(getRight(x), xm, xr);
    // t[x] = t[getLeft(x)] + t[getRight(x)];
    for(auto it : t[getLeft(x)]){
        t[x].insert(it);
    }
    for(auto it : t[getRight(x)]){
        t[x].insert(it);
    }
}



set<int> get(int l, int r, int x, int xl, int xr){
    if(xl >= r || xr <= l){
        return set<int>();
    } 
    if(xl >= l and xr <= r){
        return t[x];
    }
    int xm = (xl + xr) / 2;
    // return get(l, r, getLeft(x), xl, xm) + get(l, r, getRight(x), xm, xr);
    set<int> check, f = get(l, r, getLeft(x), xl, xm), f2 = get(l, r, getRight(x), xm, xr);
    for(auto it : f){
        check.insert(it);
    }
    for(auto it : f2){
        check.insert(it);
    }
    return check;
}


void solve(){
    int n;
    cin >> n;
    t = vector<set<int>>(4 * (n + 1));
    massive = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    build(0, 0, n);
    int q;
    cin >> q;
    repeat(q){
        int l, r;
        cin >> l >> r;
        set<int> ans = get(l - 1, r, 0, 0, n);
        if(ans.size() < 2){ 
            cout << -1 << " " << -1 << ENDL;
        } else{
            int cnt = 0;
            for(auto it : ans){
                cout << it << " ";
                cnt++;
                if(cnt >= 2){ break;}
            }
            cout << ENDL;
        }
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin >> n;
    repeat(n) solve();

    endd
}