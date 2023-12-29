#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    // stack<int> st;

    // st.push(massive[0]);
    // cout << -1 << " ";
    // for(int i = 1; i < n; i++){
    //     if(massive[i - 1] <= massive[i]){
    //         cout << massive[i - 1] << " ";
            
    //     } else{
    //         if(st.top() <= massive[i])
    //         cout << st.top() << " ";
    //         else{
    //             cout << -1 << " ";
    //         }
    //     }
    //     if(st.top() > massive[i]){
    //             st.push(massive[i]);
    //     }
    // }
    // cout << ENDL;
    vector<int> dp(n);
    dp[0] = -1;
    for(int i = 1; i < n; i++){
        if(massive[i - 1] <= massive[i]){
            dp[i] = massive[i - 1];
        } else{
            // dp[i] = dp[i - 1];
            int index = i - 1;
            while(massive[i] < dp[index]){
                index--;
            }
            dp[i] = dp[index];
        }
    }
    for(auto it : dp) cout << it << " ";

    endd
}