// Bismillah 
// لا إله إلا الله محمد رسول الله
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
map<int, int> mapa;
vector<int> dp(2 * 1e5 + 7);
void solve(int ccase){
    int n;
    cin >> n;
    cout << dp[n] << ENDL;
}

int getSum(int n){
    int x=0;
    while(n > 0){
        x += n % 10;
        n /= 10;
    }
    return x;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int MAXN = 2 * 1e5 + 7;
    for(int i = 1; i <= MAXN; i++){
        mapa[i] = getSum(i);
        dp[i] = dp[i - 1] + mapa[i];
    }

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}