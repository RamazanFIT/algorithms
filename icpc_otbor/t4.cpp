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
    multiset<string> a;
    multiset<string> b;
    multiset<string> c;
    int pa = 0, pb = 0, pc = 0;
    for(int i = 0; i < n; i++){
        string z;
        cin>>z;
        a.insert(z);
    }
    for(int i = 0; i < n; i++){
        string z;
        cin>>z;
        b.insert(z);
    }
    for(int i = 0; i < n; i++){
        string z;
        cin>>z;
        c.insert(z);
    }
    for(auto it : a){
        if(b.find(it) == b.end() and c.find(it) == c.end()){
            pa += 3;
        } else if(!(b.find(it) != b.end() and c.find(it) != c.end())){
            if(b.find(it) != b.end()){
                pa++;
              
            } else if(c.find(it) != c.end()){
                pa++;
                
            }
        }
    }
    for(auto it : b){
        if(a.find(it) == a.end() and c.find(it) == c.end()){
            pb += 3;
        } else if(!(a.find(it) != a.end() and c.find(it) != c.end())){
            if(a.find(it) != a.end()){
               
                pb++;
            } else if(c.find(it) != c.end()){
                pb++;
            
            }
        }
    }
    for(auto it : c){
        if(b.find(it) == b.end() and a.find(it) == a.end()){
            pc += 3;
        } else if(!(b.find(it) != b.end() and a.find(it) != a.end())){
            if(b.find(it) != b.end()){
                pc++;
              
            } else if(a.find(it) != a.end()){
          
                pc++;
            }
        }
    }
    cout << pa << " " << pb << " " << pc << ENDL;
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