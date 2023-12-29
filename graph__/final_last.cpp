#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin>>n;
    map<string, int> mapa1;
    // map<string, int> mapa2;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string b, a;
        cin >> b >> a;
        mapa1[a] = i + 1;
        v.pb(b);
    }
    for(int i = 0; i < n; i++){
        cout << mapa1[v[i]] << ENDL;
    }
    


    endd
}