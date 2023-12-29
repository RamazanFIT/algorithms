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

    string a, b;

    cin >> a >> b;

   
    if(b.size() <= a.size()){
        if(a.find(b) != -1){
            cout << 1;
            return 0;
        }
    }
    set<char> set_;
    for(int i = 0; i < a.size(); i++){
        set_.insert(a[i]);
    }
    for(int i = 0; i < b.size(); i++){
        if(set_.find(b[i]) == set_.end()){
            cout << -1 << ENDL;
            return 0;
        }
    }
    int l = 0, r = 0;
    int ddd = 0;
    int fff = 0;
    bool flag = true;
    int cnt = 0;

    while(true){
        if(r >= a.size()){
            cnt++;
            r = 0;
            ddd = l - 1;
            if(flag){
                fff = l - 1;
                flag = false;
            }
            if(l < b.size()){
                if(b[l] != a[0]){
                    cout << -1 << ENDL;
                    return 0;
                }
            }
            
            if(int(l - a.size() - 1) >= 0){
                if(b[int(l - a.size() - 1)] != a[a.size() - 1]){
                    // cout << (l - a.size() - 1)  << " " << a[a.size() - 1] << ENDL;
                    cout << -1 << ENDL;
                    return 0;
                }
            }
        }
        if(l >= b.size()) break;
        if(a[r] == b[l]){
            r++;
            l++;
        } else{
            r = 0;
            l++;
        }

    }
    if(int(fff - a.size() + 1) / a.size() != 0){
        cout << -1 << ENDL;
        return 0;
    }
    if(int(fff - a.size() + 1) > 0){
        if(b[(fff - a.size())] != a[a.size() - 1]){
            cout << -1 << ENDL;
            return 0;
        }
    }
    if(int(fff - a.size() + 1) % a.size() != 0) cnt++;
    else{
        if(int(fff - a.size() + 1) != 0){
            cout << -1 << ENDL;
            return 0;
        }
    }

    if(int(b.size() - ddd - 1) / a.size() != 0){
        cout << -1 << ENDL;
        return 0;
    }
   
    if(int(b.size() - ddd - 1) % a.size() != 0) cnt++;
    else{
        if(int(b.size() - ddd - 1) != 0){
            cout << -1 << ENDL;
            return 0;
        }
    }

    cout << cnt;
    

    endd
}