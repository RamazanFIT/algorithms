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

int func(int x){
    return 1 + 2 * (x - 1);
}

void solve(int ccase){
    int n, k;
    cin >> n >> k;
    int f = 1;
    int x = 0;
    int l = 1;
    int save = n;
    int last = 0;
    while(n > 0){
        f *= l++;
        x = 0;
        int zzz = n;
        // n /= f;
        // n = save / (l - 1);
        n /= (l - 1) + 1;
        if(n % 2 == 0) x += n / 2;
        else x += n / 2 + 1;
        // if(n == 0)
        // last = f func(k);
        // cout << last << ENDL;
        if(k - x <= 0){
            cout << f * func(k) << ENDL;
            last = func(k);
            return;
        } else{
            k -= x;
        }
    }
    // cout << last;

}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}