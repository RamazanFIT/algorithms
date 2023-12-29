#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<bool> bolean(n + 1);
    
    for(int i = 2; i <= sqrt(n + 1) + 1; i++){
        if(!bolean[i]){
            for(int j = i * i; j <= n; j += i){
                bolean[j] = true;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(!bolean[i]){
            cout << i << " ";
        }
    }
    // O(n) memory 
    // O(n * log (log (n))) Time complexity 
    


    endd
}