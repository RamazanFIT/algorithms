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

    string s;
    cin >> s;
    map<char, int> mapa;
    for(int i = 0; i < s.size(); i++){
        mapa[s[i]]++;
    }
    for(auto it : mapa){
        for(int i = 0; i < it.second; i++){
            cout << it.first;
        }
    }
    

    
    endd
}