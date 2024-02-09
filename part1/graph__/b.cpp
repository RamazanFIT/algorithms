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
int mod = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    vector<int> m;
    int tmp = sqrt(n);
    for(int i = 1; i <= tmp; i++){
        if(n % i == 0){
            m.pb(i);
            m.pb(n / i);
        }
    }
    int ans = 0;
    for(int j = 0; j < m.size(); j++){
        // cout << m[j] << " ";
        int minimum = INT64_MAX;
        int maximum = 0;
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cnt++;
            sum += massive[i];
            if(cnt == m[j]){
                minimum = min(minimum, sum);
                maximum = max(maximum, sum);
                sum = 0;
                cnt = 0;
            }
        }
        ans = max(maximum - minimum, ans);
    }
    if(ans >= INT64_MAX){
        cout << 0 << ENDL;
    } else{
        cout << ans << ENDL;
    }
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