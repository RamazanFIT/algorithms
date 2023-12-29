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
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<bool> w(n + 1, 0);
    
    for(int i = 2; i < sqrt(n) + 1; i++){
        if(!w[i])
        for(int j = i * i; j <= n + 1; j += i){
            w[j] = true;
        }
    }
    for(int i = 2; i <= n; i++){
        if(!w[i]) cout << i << " ";
    }
    // O(n * sqrt(n))  speed
    // O(n) memory



    endd
}