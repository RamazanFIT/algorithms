// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    char a;
    cin >> a;
    int cnt = 0;
    map<char, vector<int>> mapa;
    for(int i = 0; i < 2 * n; ++i){
        char mask;
        char type;
        // cin >> mask >> type;
        string s;
        cin >> s;
        mask = s[0];
        type = s[1];
        mapa[type].pb(int(mask - '0'));
        // cout << s <<  int(mask - '0') << ENDL;
    }
    vector<pair<string, string>> ans;
    int l = 0;
    // sort(all(mapa[a]));
    for(auto it : mapa){
        sort(all(mapa[it.first]));
    }
    for(auto it : mapa){
        if(it.first == a) continue;
        
        vector<int> mass = it.second;

        int mid = mass.size() / 2;
        for(int i = 0; i < mid; i++){
            // cout << mass[i] << it.first << " " << mass[mass.size() - 1 - i] << it.first;
            string s1 = to_string(mass[i]) + it.first;
            string s2 = to_string(mass[mass.size() - 1 - i]) + it.first;
            ans.pb({s1, s2});
        }
        if(mass.size() % 2 != 0){
            // cout << mass[mid] << it.first << " " << mapa[a][l++] << a;
            if(l >= mapa[a].size()){
                cout << "IMPOSSIBLE" << ENDL;
                return;
            }
            string s1 = to_string(mass[mid]) + it.first;
            string s2 = to_string(mapa[a][l++]) + a;
            ans.pb({s1, s2});

        }
    }
    if((mapa[a].size() - l) % 2 != 0){
        cout << "IMPOSSIBLE" << ENDL;
                return;
    }
    int len = (mapa[a].size() - l) / 2;
    // for(auto it : ans){
        
    //     cout << it.first << " " << it.second << ENDL;
    // }
    // cout << "after\n";
    int jojo = 0;
    for(int i = l; i < l + len; i++){
        string s1 = to_string(mapa[a][i]) + a;
        string s2 = to_string(mapa[a][mapa[a].size() - 1 - jojo++]) + a;
        ans.pb({s1, s2});

    }
    // cout << "fefew" << mapa[a][mapa.size() - 1] << "fewfewf" << ENDL;
    // for(auto it : mapa){
    //     cout << it.first << ": ";
    //     for(auto i : mapa[it.first]){
    //         cout << i << " ";
    //     } cout  << ENDL;
    // }
    for(auto it : ans){
        cout << it.first << " " << it.second << ENDL;
    }


}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) solve();

    endd
}