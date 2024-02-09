#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


bool comp(pair<string, string> a, pair<string, string> b){
    for(int i = 0; i < a.ff.size(); i++){
        if(a.ss[i] < b.ss[i]){
            return true;
        } else if(a.ss[i] > b.ss[i]){
            return false;
        }
    }
    for(int i = 0; i < a.ff.size(); i++){
        if(a.ff[i] < b.ff[i]){
            return false;
        } else if(a.ss[i] > b.ss[i]){
            return true;
        }
    }
    return true;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<string, string> > massive;
    while(n--){
        string a, b;
        cin >> a >> b;
        massive.push_back(make_pair(a, b));
    }

    sort(all(massive), comp);

    int ans = 1;

    string last = massive[0].ss;
    for(int i = 1; i < massive.size(); i++){
        if(last == massive[i].ff){
                ans++;
                last = massive[i].ss;
                continue;
        }
        for(int j = 0; j < last.size(); j++){
            
            
            if(last[j] < massive[i].ff[j]){
                ans++;
                last = massive[i].ss;
                break;
            } else if(last[j] > massive[i].ff[j]){
                break;
            }
        }
    }
    cout << ans << ENDL;
    
    endd
}