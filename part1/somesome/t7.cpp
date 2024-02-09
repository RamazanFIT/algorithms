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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> w(n);
    for(auto &it : w){
        cin >> it;
    }
    int m;
    cin >> m;
    vector<int> a(m);
    for(auto &it : a){
        cin >> it;
    }
    sort(all(w));
    sort(all(a));
    int cnt = 0;
    vector<bool> visited(m);
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < m; j++){
            if(!visited[j])
            if(abs(w[i] - a[j]) <= 1){
                cnt++;
                visited[j] = true;
                break;
            }
        }
    }
    cout << cnt;
    


    endd
}