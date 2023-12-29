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

    multiset<int> ll, rr;
    int q;
    cin >> q;
    while(q--){
        char type; 
        int a, b; 
        cin >> type >> a >> b;
        
        if(type == '-'){
            ll.erase(ll.find(a));
            rr.erase(rr.find(b));
        } else{
            ll.insert(a);
            rr.insert(b);
        }
        int l = INT_MIN, r = INT_MAX;
        if(ll.size() != 0){
            auto it = ll.end();
            it--;
            l = *it;
        }
        if(rr.size() != 0){
            r = *(rr.begin());
        }
        if(l > r){
            cout << "YES" << ENDL;
        } else{
            cout << "NO" << ENDL;
        }
    }
    


    endd
}