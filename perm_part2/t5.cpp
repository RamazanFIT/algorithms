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
    freopen("comb2.out", "w", stdout);

    int n, k;
    int32_t c;
    cin >> n >> k >> c;
    vector<bool> bolean(n, 1);
    for(int i = 0; i < k; i++){
        bolean[i] = 0;
    }
    // for(int i = 0; i < c; i++){
    //     next_permutation(all(bolean));
    // }
    // for(int i = 0; i < n; i++){
    //     if(bolean[i] == 0){
    //         cout << i + 1 << " ";
    //     }
    // }
    int cnt = 1;
    do
    {   
        cout << cnt << ENDL;
        for(int i = 0; i < n; i++){
        if(bolean[i] == 0){
            cout << i + 1 << " ";
        }
        } cout << ENDL;
        if(cnt > 500) break;
        cnt++;
    } while (next_permutation(all(bolean)));
    
    


    endd
}