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
    string s;
    cin >> s;
    string a = s;
    sort(all(a));
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    } cout << ENDL;
    for(int i = 0; i < s.size(); i++){
        cout << a[i] << " ";
    }
}
// wygnotgsno wgnotgsno gnotgsno  gnogsno gngsno  ggsno ggno ggn gg g
// wygnotgsno wgnotgsno gnotgsno  gnogsno gnogsn gngsn gngs ggs gg g
// 10 + 9 + 8 + 7 + 6 + 5
// s 
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}