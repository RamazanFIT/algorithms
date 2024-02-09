#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int fact(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fact(n - 1);
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int ans = 0;
    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    vector<int> used(n, 0);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < massive[i] - 1; j++){
            if(!used[j]){
                cnt++;
            }
        }
        used[massive[i] - 1] = true;
        ans += fact(n - 1 - i) * cnt;
    }
    cout << ans + 1 << ENDL;
    


    endd
}