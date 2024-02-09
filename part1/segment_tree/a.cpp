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
    cin >> n;
    int a, b, c;
    c = n - 3;
    if(c <= 2){
        cout << "No" << ENDL;
            return;
    }
    if(c % 3 == 0){
        if(c - 2 > 0){
            b = 2;
            a = 1;
            b += 2;
            
            set<int> set_;
            set_.insert(a);
            set_.insert(b);
            set_.insert(c - 2);
            if(set_.size() == 3){
                cout << "Yes" << ENDL;
                cout << a << " " << b << " " << c - 2 << ENDL;
            }
            
            else{
                cout << "No" << ENDL;
            return;
            }
        } else{
            cout << "No" << ENDL;
            return;
        }
    } else{
        a = 1;
        b = 2;
        set<int> set_;
            set_.insert(a);
            set_.insert(b);
            set_.insert(c);

            if(set_.size() == 3){
                cout << "Yes" << ENDL;
                cout << a << " " << b << " " << c << ENDL;
            }
            
            else{
                cout << "No" << ENDL;
            return;
            }
  
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}