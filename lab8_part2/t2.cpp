#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

struct Abstr{
    // Abstr * w[27];
    vector<pair<char, Abstr *> > v;
    // bool has(char a){
    //     return get(a) != NULL;
    // }
    // Abstr * get(char a){
    //     return w[a - 'a'];
    // }

    void put(char a, Abstr * fff){
        v.push_back(make_pair(a, fff));
    }
    bool has(char a){
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == a) return true;
        }
        return false;
    }

    Abstr * get(char a){
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == a) return v[i].second;
        }
        return NULL;
    }
};



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s;
    cin >> s;
    unsigned long long ans = 0;
    Abstr * root = new Abstr();

    for(int i = 0; i < s.size(); i++){
        Abstr * tmp = root;
        for(int j = i; j < s.size(); j++){
            if(!tmp->has(s[j])){
                tmp->put(s[j], new Abstr());
                ans++;
            }
            tmp = tmp->get(s[j]);
        }
    }
    cout << ans;
    


    endd
}