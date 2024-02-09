#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
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

    int k = 2 * 1e6 + 5;

    vector<int> phi(k);
    vector<int> bolean(k);
    for(int i = 2; i < k; i++){
        if(bolean[i]) continue;
        int sum = 0;
        int x = i;
        int cnt = 2;
        while(x > 1){
            int j = 0;
            while(x % cnt == 0){
                j++;
                x /= cnt;
            }
            sum += j * (cnt - 1);
            cnt++;
        }
        phi[i] = sum;
        x = i;
        cnt = 2;
        while(x * i <= k){
            phi[x * i] = cnt * phi[i];
            bolean[x * i] = true;
            cnt++;
            x *= i;
        }
        bolean[i] = true;
        cout << i << " ";
    }
    // for(int i = 1; i <= 15; i++ ) cout << i << ":" <<  phi[i] <<ENDL;
    cout << "YEDS";
    


    endd
}