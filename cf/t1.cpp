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
    vector<int> massive(n + 1);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        massive[i + 1] = massive[i] + a;
    }
    
    int m;
    cin>>m;
    for(int i = 0; i < m; i++){
        int a;
        cin>>a;
        cout << lower_bound(all(massive), a) - massive.begin() << ENDL;
    }
    cout << ENDL;


    endd
}