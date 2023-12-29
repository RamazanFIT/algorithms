#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;
    map<int, int> mapa;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mapa[a]++;
    }
    vector<pair<int, int> > dp(mapa.size() + 1);
    dp[0] = make_pair(0, 0);
    map<int, int> :: iterator it = mapa.begin();
    int ans = 0;
    for(int i = 1; i < dp.size(); i++){
        dp[i].first = it->first;
        dp[i].second = dp[i - 1].second + it->second;
        it++;
    }
    for(int i = 1; i < dp.size(); i++){
        // ans = max(ans, )
        if(dp[i].ff - dp[i - 1].ff == 1){
            // ans = max(ans, dp[mapa.size()].ss - dp[i - 1].ss + min(dp[i - 1].ss, k));
            if(dp[i].ff <= (dp[dp.size() - 1].ss - dp[i - 1].ss + min(mapa[dp[i - 1].ff], k))){
                ans = max(ans, dp[i].ff);
            }
        } 
        if(dp[i].ff <= (dp[dp.size() - 1].ss - dp[i - 1].ss)){
            ans = max(ans, dp[i].ff);
        }
        if((dp[i].ff + 1) <= (dp[dp.size() - 1].ss - dp[i].ss + min(mapa[dp[i].ff], k))){
            ans = max(ans, dp[i].ff + 1);
        }
        if(i < dp.size() - 1)
        for(int j = dp[i].ff; j <= dp[i + 1].ff; j++){
            if((j) <= (dp[dp.size() - 1].ss - dp[i].ss)){
                ans = max(ans, j);
            }
        }
        // cout << dp[i + 1000].ff << " ";
    } //cout << ENDL;
    
    cout << ans << ENDL;

    // for(int i = 0; i < dp.size(); i++){
    //     cout << dp[i].ff << "  " << dp[i].ss << ENDL;
    // }



    endd
}