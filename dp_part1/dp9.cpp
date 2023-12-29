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
    freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];

    vector<int> dp(n + 1);
    dp[0] = INT_MAX;
    dp[1] = numbers[0];
    for(int i = 0; i < n; i++) cout << numbers[i] << " ";cout << ENDL;
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + numbers[i - 1];
    }
    cout << dp[n] << ENDL;
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";cout << ENDL;
    vector<int> path(n + 1);
    path[1] = dp[1];
    for(int i = 2; i <= n; i++){
        int c = dp[i] - numbers[i - 1];
        if(c == dp[i - 1]){
            path[i] = i - 1;
        } else{
            path[i] = i -  2;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << path[i] << " ";
    // } cout << ENDL;

    int index = n;
    cout << 0 << " ";
    for(;;){
        if(index <= 0) break;
        cout << numbers[path[index] - 1] << " ";
        index = path[index];
    }


    // vector<int> path;
    // path.push_back(numbers[n - 1]);
    // int index = n;
    // for(;;){
    //     if(index <= 0){
    //         break;
    //     }
    //     if(dp[index] - numbers[index - 1] == dp[index - 1]){
    //         path.push_back(numbers[index - 2]);
    //         index--;
    //     } else{
    //         path.push_back(numbers[index - 3]);
    //         index--;
    //         index--;
    //     }
    // }
    // for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << " "; cout << ENDL;

    // 242 24423 23 1313 3132423 23467 57646 5345 34534 5343 1 3 0 
    // 35734
    // 242 24665 265 1578 3132688 25045 82691 30390 64924 35733 35734 35736 35734 
    // 0 242 23 1313 23467 5345 5343 1 0 

    endd
}