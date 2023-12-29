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

    int n, m;
    cin >> n >> m;
    vector<vector<int> > massive(m, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> massive[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        sort(massive[i].rbegin(), massive[i].rend());
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << massive[j][i] << " "; cout << ENDL;
    }

    endd
}