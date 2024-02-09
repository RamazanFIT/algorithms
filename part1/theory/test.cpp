#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck

    int n;
    cin >> n;
    int k;cin>>k;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];

    int sum = massive[0];
    int cnt = 1;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(cnt < k and massive[i] - massive[i - 1] == 1){
            ans = max(ans, sum / cnt);
            sum += massive[i];
            cnt++;
            ans = max(ans, sum / cnt);
        } else{
            cnt = 1;
            sum = massive[i];
        }
    }

    cout << ans;


    endd 
}