#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
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
    int q;
    cin >> q;
    vector<vector<bool> > adj(n + 1, vector<bool>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool a;
            cin >> a;
            adj[i][j] = a;
        }
    }
    
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int cnt = 0;
        cnt += adj[a][b];
        cnt += adj[a][c];
        cnt += adj[b][c];
        if(cnt == 3){
            cout << "YES" << ENDL;
        } else{
            cout << "NO" << ENDL;
        }
    }


    endd
}