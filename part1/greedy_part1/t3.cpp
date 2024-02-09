#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.ff - a.ss < b.ff - b.ss){
        return true;
    } else if(a.ff - a.ss == b.ff - b.ss){
        if(a.ff > b.ff) return true;
        else return false;
    } else{
        return false;
    }
}

void solve(){
    int n, r;
    cin >> n >> r;
    vector<pair<int, int> > massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i].first;
    } 
    for(int i = 0; i < n; i++){
        cin >> massive[i].second;
    } 
    sort(all(massive), comp);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(r >= massive[i].first){
            cnt += (r - massive[i].first) / (massive[i].first - massive[i].second) + 1;
            r -= ((r - massive[i].first) / (massive[i].first - massive[i].second) + 1) * (massive[i].ff - massive[i].ss);
        }
    }
    cout << cnt << ENDL;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}