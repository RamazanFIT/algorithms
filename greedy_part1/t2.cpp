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

    int n, k;
    cin >> n >> k;
    vector<int> massive(n);
    vector<int> boolean(n, 0);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
        if(massive[i] > k){
            cout << "Impossible";
            endd
        }
    }
    sort(all(massive));
    int left = 0;
    int right = n - 1;
    int ans = 0;
    while(right >= left){
        if(right == left){
            ans++;
            break;
        }
        if(massive[right] + massive[left] <= k){
            ans++;
            left++;
            right--;
        } else{
            ans++;
            right--;
        }
    }
    cout << ans << ENDL;


    endd
}