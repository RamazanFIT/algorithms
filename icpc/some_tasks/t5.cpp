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
    int w[n + 1];
    for(int i = 1; i <= n; i++) cin >> w[i];
    vector<int> massive(n + 1, 0);

    massive[1] = 0;
    massive[2] = abs(w[2] - w[1]);
    for(int i = 3; i <= n; i++){
        if(abs(w[i] - w[i - 1]) + massive[i - 1] >= abs(w[i] - w[i - 2]) + massive[i - 2])
        massive[i] = abs(w[i] - w[i - 2]) + massive[i - 2];
        else massive[i] = abs(w[i] - w[i - 1]) + massive[i - 1];
    }
    cout << massive[n] << ENDL;
    


    endd
}