#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<vector<int> > dp(1005, vector<int>(1005, 0));




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    set<int> set_;
    vector<int> massive;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
     
            set_.insert(a);
            massive.push_back(a);

    }
    vector<int> sorted;
    for(auto it : set_){
        sorted.push_back(it);
    }
  
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sorted.size(); j++){
            if(massive[i - 1] == sorted[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][sorted.size()] << ENDL;
    
    


    endd
}