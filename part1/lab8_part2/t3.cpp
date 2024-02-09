#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


struct f{
    int a;
    int b;
    f(int a, int b){
        this->a = a;
        this->b = b;
    }
};


bool comp(f aa, f bb){
    return aa.a + aa.b < bb.a + bb.b;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    vector<f> v;
    v.push_back(f(342, 2));
    
    v.push_back(f(2, 3));
    v.push_back(f(432432, 2));
    v.push_back(f(323, 2));
    v.push_back(f(342, 2));
    v.push_back(f(2323, 2));
    v.push_back(f(23232, 2));
    sort(all(v), comp);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].a << " " << v[i].b << ENDL;
    }


    endd
}