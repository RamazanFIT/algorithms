#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
set<string> check;


void solve(){
    int n;
    cin>>n;
    string a;
    cin >> a;
    reverse(all(a));
    string ans = "";
    string tmp = "";
    for(int i = 0; i < tmp.size(); i++){
        if(check.find(tmp) != check.end()){
            ans += tmp + ".";
            tmp = "";
        } else{
            tmp = a[i] + tmp;
        }
    }
    // for(int i = 0; i < ans.size() - 1; i++) cout << ans[i]; cout << ENDL;

    // cout << ans << " ";
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    char v[] = {'a', 'e'};
    char c[] = {'b', 'c', 'd'};


    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 2; j++){
            // string tmp = c[i] + v[j];
            string tmp = "";
            tmp += c[i];
            tmp += v[j];
            check.insert(tmp);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 2; j++){
            for(int k = 0; k < 3; k++){
                string tmp = "";
                tmp += c[i];
                tmp += v[j];
                tmp += c[k];
                check.insert(tmp);

            }
            
                // check.insert(c[i] + v[j] + c[k] + "");
        }
    }
    int t;cin>>t;repeat(t) solve();
    
    

    endd
}