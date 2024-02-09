#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    string s;
    cin >> s;
    int x;
    cin >> x;
    int index = 0;
    int cnt = 0;
    int z = s.size();
    for(int k = 0; k <= z * 2; k++){
        // cout << s << ENDL;
        if(cnt >= x){
            cout << s[s.size() - (cnt - x) - 1];
            return;
        }
        if(index == s.size() - 1){
            cnt += s.size();
            if(cnt >= x){
                cout << s[s.size() - (cnt - x) - 1];
                return;
            }
            s.erase(s.begin() + index);
            // index--;
            index = max(0ll, index - 1);
            
            continue;
        }
        if(int(s[index]) > int(s[index + 1])){
            cnt += s.size();
            if(cnt >= x){
                cout << s[s.size() - (cnt - x) - 1];
                return;
            }
            s.erase(s.begin() + index);
            // index--;
            index = max(0ll, index - 1);
            continue;
        }
       
        index++;
    }
    cout << s;
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