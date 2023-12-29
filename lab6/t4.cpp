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
    set<string> searching;
    map<string, string> mapa1;
    map<string, string> mapa2;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        
        if(searching.find(s1) == searching.end()){
            mapa1[s1] = s2;
            mapa2[s2] = s1;
            searching.insert(s2);
        } else{
            mapa1[mapa2[s1]] = s2;
        }
        
    }
    while(true){
        bool flag = true;
        for(auto  it : mapa1){
            if(it.first == it.second) continue;
            if(mapa1.find(it.second) != mapa1.end()){
                mapa1[it.first] = mapa1[it.second];
                mapa1.erase(it.second);
                flag = false;
                break;
            }
        }
        if(flag) break;
    }
    cout << mapa1.size() << ENDL;
    for(auto it : mapa1){
        cout << it.first << " " << it.second << ENDL;
    }
    


    endd
}