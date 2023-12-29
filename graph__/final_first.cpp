#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int k = 2000001;

    vector<int> phi(k);
    for(int i = 2; i < k; i++){
        int cnt = 0;
        int tmp = i;
        int div = 2;
        int ans = 0;
        int kkk = 0;
        int bbb = sqrt(i);
        while(tmp > 1){
            if(div >= bbb) break;
            while(tmp % div == 0){
                cnt++;
                tmp /= div;
                kkk++;
            }
            ans += (div - 1) * cnt;
            cnt = 0;
            div++;
            kkk++;
        }
        // if(tmp != 1){
            ans += tmp - 1;
        // }
        phi[i] = ans;
        // cout << phi[i] << " ";
        // cout << kkk << " ";
    }
    // for(int i = 1; i < 20; i++){
    //     cout << phi[i] << " ";
    // }
    // cout << phi[13] << ENDL;
    vector<int> delp(k);
    for(int i = 2; i < k; i++){
        int cnt = 0;
        int tmp = i;
        while(tmp > 1){
            // cout << tmp << ENDL;
            tmp = phi[tmp];
            cnt++;
        }
        delp[i] = cnt;
    }
    cout << delp[13] << ENDL;
    int tmp = 0;
    // for(int i = 0; i < k; i++){
    //     tmp += delp[i];
    //     cout << tmp << " ";
    // }


    endd
}