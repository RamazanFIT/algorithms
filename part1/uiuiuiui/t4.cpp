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

vector<map<int, int>> t;
vector<int> massive;

int getLeft(int x){
    return x * 2 + 1;
}

int getRight(int x) { return x * 2 + 2;}

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        // t[x].insert(massive[xl]);
        t[x][massive[xl]] = xl;
        return;
    }
    int xm = (xl + xr) / 2;
    
    build(getLeft(x), xl, xm);
    build(getRight(x), xm, xr);
    // t[x] = t[getLeft(x)] + t[getRight(x)];
    if(t[x].size() >= 2){
        return;
    }
    for(auto it : t[getLeft(x)]){
        t[x].insert(it);
        // t[x][it.first] = it.second; 
    //     if(t[x].size() >= 2){
    //     return;
    // }
    }
    if(t[x].size() >= 2){
        return;
    }
    for(auto it : t[getRight(x)]){
        t[x].insert(it);
    //     if(t[x].size() >= 2){
    //     return;
    // }
        // t[x][it.first] = it.second; 
    }
}
// 

bool flag = false;
int ans1 = -1, ans2 = -1;
map<int, int> get(int l, int r, int x, int xl, int xr){
    if(flag) return map<int, int>();
    if(xl >= r || xr <= l){
        return map<int, int>();
    } 
    if(xl >= l and xr <= r){
        return t[x];
    }
    int xm = (xl + xr) / 2;
    
    // return get(l, r, getLeft(x), xl, xm) + get(l, r, getRight(x), xm, xr);
    map<int, int> check, f = get(l, r, getLeft(x), xl, xm), f2 = get(l, r, getRight(x), xm, xr);
    for(auto it : f){
        check.insert(it);
        
    }
    for(auto it : f2){
        check.insert(it);
    }
    // cout << check.size() << ENDL;
    if(check.size() >= 2){
        // cout << "ewfewfwefewf" << ENDL;
        flag = true;
        int cnt = 0;
        for(auto it : check){
            if(cnt == 0){
                ans1 = it.second;
            } else{
                ans2 = it.second;
                break;
            }
            cnt++;
        }
    }
    return check;
}


void solve(){
    int n;
    cin >> n;
    flag = false;
    t = vector<map<int, int>>(4 * (n + 1));
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
        ans1 = -1;
        ans2 = -1;
        flag = false;
        // get(l - 1, r, 0, 0, n).size();
        map<int, int> koko = get(l - 1, r, 0, 0, n);

        if(flag){
            cout << ans1 + 1 << "  " << ans2 + 1 << ENDL;
        } else{
            // map<int, int> koko = get(l - 1, r, 0, 0, n);
            if(koko.size() >= 2){
                int cnt = 0;
                for(auto it : koko){
                    if(cnt >= 2) break;
                    cout << it.second + 1 << " ";
                    cnt++;
                }
                cout << ENDL;
            } else{
                cout << -1 << " " << -1 << ENDL;
            }
        }
    }
    cout << ENDL;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin >> n;
    repeat(n) solve();

    endd
}