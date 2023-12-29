#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    map<int, int> w;
    map<int, map<int, int>> mapa;
    set<int> thr;
    repeat(n){
        int a, b;
        cin >> a >> b;
        w[a]++;
        mapa[a][b]++;
        thr.insert(a);
    }
    int ans = 0;
    for(auto it : thr){
        int cnt = INT_MAX;
        for(auto some_pair : mapa[it]){
            int x = some_pair.first;
            int y = some_pair.second;
            if(y - x >= 0){
                cnt = min(cnt, y - x + (w[it] - y));
            }
            if(y - x < 0){
                cnt = min(cnt, x - y + (w[it] - y));
            }

        }
        cnt = min(cnt, w[it]);
        ans += cnt;
    }
    cout << ans;
    


    endd
}