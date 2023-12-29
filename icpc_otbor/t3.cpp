#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s = "Timur";
    map<char, int> check;
    map<char, int> mapa;
    for(auto it : s){
        check[it]++;
    }
    for(int i = 0; i < n; i++){
        char a;
        cin>>a;
        mapa[a]++;
    }
    if(mapa == check){
        cout << "YES" << ENDL;
    } else cout << "NO" << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}