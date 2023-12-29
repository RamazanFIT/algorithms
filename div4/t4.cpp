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
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> massive;
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(a == 'B'){
            massive.push_back(i);
        }
    }
    int ans = 0;
    int left = 0;
    int right = 0;
    while(right < massive.size() and left < massive.size()){
        while(right < massive.size() and massive[right] - massive[left] <= k - 1){
            right++;
        }
        left = right;
        ans++;
    }
    cout << ans << ENDL;
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