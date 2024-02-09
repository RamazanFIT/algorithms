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

    int n, k;
    cin>>n>>k;
    k %= n;
    vector<string> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];

    for(int i = k; i < n; i++){
        cout << massive[i] << " ";
    }
    for(int i = 0; i < k; i++){
        cout << massive[i] << " ";
    }
    cout << ENDL;
    


    endd
}