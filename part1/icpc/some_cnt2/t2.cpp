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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int> > massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i].first >> massive[i].second;
    }
    sort(all(massive));
    int anss = 0;
    int hhh = min(int(3 * (sqrt(n) + 1)), n);
    for(int j = 0; j < hhh; j++){
        int ans = 1;
        int last = massive[j].second;
        for(int i = 0; i < n; i++){
            if(last <= massive[i].first){
                last = massive[i].second;
                ans++;
            }
        }
        anss = max(anss, ans);
    }
    int ccc = max(0ll, int(n - 3 * (sqrt(n) + 1)));
    for(int j = n - 1; j >= ccc; j--){
        
        int ans = 1;
        int last = massive[j].first;
        for(int i = n - 1; i >= 0; i--){
            if(last >= massive[i].second){
                last = massive[i].first;
                ans++;
            }
        }
        anss = max(anss, ans);
    }
    cout << anss << ENDL;


    


    endd
}