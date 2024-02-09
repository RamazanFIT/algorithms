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
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];

    int left = 1;
    int right = n - 1;
    int a = massive[0];
    int b = 0;
    int order = 1;
    bool flag = false;
    int sum = a;
    int cnt = 0;
    int ans = 0;
    while(true){
        if(order % 2 != 0){
            while(cnt <= sum){
                if(right < left){
                    flag = true;
                    break;
                }
                cnt += massive[right];
                right--;
            }

            b += cnt;
            sum = max(sum, cnt);
            if(cnt != 0)
            ans++;
            cnt = 0;
        } else{
            while(cnt <= sum){
                if(left > right){
                    flag = true;
                    break;
                }
                cnt += massive[left];
                left++;
            }
            a += cnt;
            sum = max(sum, cnt);
            if(cnt != 0)
            ans++;
            cnt = 0;
        }
        // cout << left << " " << right << ENDL;
        
  
        order++;
        if(flag){
            break;
        }
    }
    // if(n == 1) order = 1;
    // else if(n == 2) order = 2;
    // else if(n % 2 == 0) order--;
    cout << ans + 1 << " " << a << " " << b << ENDL;
    
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}