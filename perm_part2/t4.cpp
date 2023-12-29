#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int C(int n, int k){
    int a = 1;
    int b = 1;
    for(int i = 1; i <= k; i++) b *= i;
    for(int i = n; i > k; i--){
        a *= i;
    }
    return a / b - 1;
}


signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    freopen("comb1.out", "w", stdout);

    int n, k, c;
    cin >> n >> k >> c;
    vector<bool> used(n, 0);
    // cout << C(n, k);
    if(c == C(n, k)){
        for(int i = n - k + 1; i <= n; i++){
            cout << i << " ";
        }
        return 0;
    }
    if(n == k){
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        } return 0;
    }
    int d = 0;
    for(int i = 0; i < k; i++){
        int cnt1 = 0;
        for(int j = d; j < n; j++){
            if(used[j]) {continue;}
            int f = 1;
            // for(int z = n - 1 - j - i; z > n - 1 - j - (k - 1 - i); z--){
            //     f *= z;
            // }
            int cnt = max(k - 1 - i, 0);
            int z = n - 1 - i - cnt1;
            z = max(0, z);
            while(cnt--){
                f *= z;
                z--;
            }
            f = max(1, f);
            // cout << f << ENDL;
            // cout << c << " >= " << f << ENDL;
            
            if(c >= f){
                c -= f;
                cnt1++;
            } else{
                // cout << c << " <= " << f << ENDL;
                cout << j + 1 << " ";
                used[j] = true;
                d = j + 1;
                break;
            }
            
        } 
        
    }
    


    endd
}