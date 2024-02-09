// 
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    vector<unsigned long long> pp(65);
    set<unsigned long long> check;
    map<int, int> check_check;
    pp[0] = 1;
    check.insert(1);
    check_check[1] = 0;
    for(int i = 1; i <= 64; i++){
        pp[i] = pp[i - 1] * 2;
        check.insert(pp[i]);
        check_check[pp[i]] = i;
    }
    map<int, int> mapa;
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(check.find(a) != check.end()){
            ans += mapa[check_check[a] - a]++;
        } else{
            ans += mapa[a]++;
        }
    }
    cout << ans << ENDL;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();
    


    endd
}