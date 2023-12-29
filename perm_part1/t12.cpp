#include <bits/stdc++.h>
#define ENDL "\n"
#define int ll

using ll = unsigned long long;

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    sort(s.begin(), s.end());
    string ans = "";
    vector<int> factorial(s.size() + 3, 1);
    for(int i = 1; i <= s.size() + 1; i++){
        factorial[i] = factorial[i - 1] * i;
    }
    if(n == factorial[s.size()]){
        cout << s << ENDL;
        return;
    }
    n %= factorial[s.size()];
    vector<bool> used(30, 0);
    for(int j = 0; j < s.size(); j++){
        for(int i = 0; i < s.size(); i++){
            if(used[int(s[i])]) continue;

            if(n >= factorial[s.size() - 1 - j]){
                n -= factorial[s.size() - 1 - j];
                
            } else{
                ans += s[i];
                used[int(s[i])] = true;
                break;
            }
        }
    }
    cout << ans << ENDL;
    return;
}


// t12.cpp == t11.cpp
signed main(){
    

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) solve();
    


}