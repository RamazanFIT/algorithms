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
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) {
        cin >> massive[i];
    }
    sort(all(massive));
    vector<int> dp(n);
    dp[0] = massive[0];
    for(int i = 1; i < n; i++) dp[i] = dp[i - 1] + massive[i];
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        int index;
        int left = -1;
        int right = n;
        while(right - left > 1){
            int mid = (right + left) / 2;
            if(massive[mid] == a){
                left = mid;
                break;
            } else if(massive[mid] < a){
                left = mid;
            } else{
                right = mid;
            }
        }
        index = left;
        while(massive[index] == massive[index + 1]) index++;
        cout << index + 1<< " " << dp[index] << ENDL;
    }
    
    


    endd
}