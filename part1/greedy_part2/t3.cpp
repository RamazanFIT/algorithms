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

    set<int> set_;

    for(int i = 0; i < n; i++){
        int a;cin>>a;
        if(set_.empty()) set_.insert(a);
        else{
            if(a > *set_.begin()){
                for(auto it = set_.rbegin(); it != set_.rend(); it++){
                    if(a > *it){
                        set_.erase(*it);
                        set_.insert(a);
                        break;
                    }
                }
            } else{
                set_.insert(a);
            }
        }
    }
    
    cout << set_.size() << ENDL;

    endd
}