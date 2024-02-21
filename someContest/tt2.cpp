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
int mmod;
vector<int> t;
vector<int> massive;

int getLeft(int x){
    return x * 2 + 1;
}

int getRight(int x) { return x * 2 + 2;}

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl] % mmod;
        return;
    }
    int xm = (xl + xr) / 2;
    
    build(getLeft(x), xl, xm);
    build(getRight(x), xm, xr);
    t[x] = ((t[getLeft(x)] % mmod) * (t[getRight(x)] % mmod)) % mmod;
}

void seT(int i, int v, int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = v;
        return;
    }
    int xm = (xl + xr) / 2;
    if(i < xm) seT(i, v, getLeft(x), xl, xm);
    else seT(i, v, getRight(x), xm, xr);
    t[x] = ((t[getLeft(x)] % mmod) * (t[getRight(x)] % mmod)) % mmod;

}

int get(int l, int r, int x, int xl, int xr){
    if(xl >= r || xr <= l){
        return 1;
    } 
    if(xl >= l and xr <= r){
        return t[x] % mmod;
    }
    int xm = (xl + xr) / 2;
    return ((get(l, r, getLeft(x), xl, xm) % mmod) * (get(l, r, getRight(x), xm, xr) % mmod)) % mmod;
}


void solve(){
    int n;
    cin >> n;
    cin >> mmod;
   
    t = vector<int>(4 * (n + 1));
    massive = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    build(0, 0, n);
    string s;
    cin >> s;
    int l = 0;
    int r = n - 1;
    for(auto it : s){
        cout << get(l, r + 1, 0, 0, n) << " ";
        if(it == 'L'){
            l++;
        } else{
            r--;
        }
    }
    cout << ENDL;
    // repeat(q){
    //     char type;
    //     int l, r;
    //     cin >> type >> l >> r;
    //     if(type == 'A'){
    //         seT(l - 1, r, 0, 0, n);
    //     } else{
    //         cout << get(l - 1, r, 0, 0, n) << ENDL;
    //     }
    // }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) solve();
    





    endd
}