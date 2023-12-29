#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int fact(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fact(n - 1);
}


void solve(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    sort(all(s));
    vector<char> used(30, 0);
    vector<int> factorial(s.size() + 2, 1);
    factorial[0] = 1;
    for(int i = 1; i <= s.size() + 1; i++){
        factorial[i] *= factorial[i - 1] * i;
    }
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        int cnt = 0;
        string tmp = "";
        for(int j = 0; j < s.size(); j++){
            // if(s[j] == s[i]) break;

            if(!used[s[j]]){
                if(factorial[s.size() - 1 - i] < n){
                    n -= factorial[s.size() - 1 - i];
                    tmp = s[j];
                } else{
                    ans += tmp;
                    used[tmp[0]] = true;
                    break;
                }
            }
        }
    }
    cout << ans << ENDL;
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