#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> color(n);
    vector<pair<int, int> > dp;
    for(int i = 0; i < n; i++){
        cin >> color[i];
        dp.push_back(make_pair(color[i], i));
    }
    // vector<int> ans(k, 0);
    sort(dp.rbegin(), dp.rend());

    int min = INT_MAX;
    int max = INT_MIN;
    vector<int> ans(k + 1, 0);
    for(int i = 0; i < dp.size(); i++){
        min = std::min(min, dp[i].second);
        max = std::max(max, dp[i].second);
        ans[dp[i].first] = 2 * (max - min + 1);


    }
    for(auto i = 1; i <= k; i++){
        cout << ans[i] << " ";
    }
    cout << ENDL;

    
    
    
    
    
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}