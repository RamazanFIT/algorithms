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
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    vector<bool> bolean(10000000, 0);
    bolean[1] = true; 
    for(int i = 2; i < sqrt(10000000) + 1; i++){
        if(!bolean[i])
        for(int j = i * i; j < 10000000; j+=i){
            bolean[j] = true;
        }
    }
    int cnt = 0;
    int super_prime = 0;
    for(int i = 2; i < 10000000; i++){
        
        if(!bolean[i]) cnt++;

        if(!bolean[i] and !bolean[cnt]){
            super_prime++;
        }
        if(super_prime == n){
            cout << i << ENDL;
            return 0;
        }
        
    }
    


    endd
}