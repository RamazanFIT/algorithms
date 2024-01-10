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


void solve(){
    int n;
    cin >> n;
    vector<int> ca(n), cb(n), cc(n);
    for(int i = 0; i < n; i++){
        cin >> ca[i];
    }
   
    for(int i = 0; i < n; i++){
        cin >> cb[i];

    }
    
    for(int i = 0; i < n; i++){
        cin >> cc[i];


    }
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){

        pq.push({ca[i], i});
    }
    vector<int> a, b, c;
    set<pair<int, pair<int, int>>> check;

    repeat(3){
        int x = pq.top().second;
        pq.pop();
        if(check.find({ca[x], {cb[x], cc[x]}}) != check.end()) continue;

        a.push_back(ca[x]);
        b.push_back(cb[x]);
        c.push_back(cc[x]);
        check.insert({ca[x], {cb[x], cc[x]}});
    }
    pq = priority_queue<pair<int, int>>();
    for(int i = 0; i < n; i++){

        pq.push({cb[i], i});
    }

    repeat(3){
        int x = pq.top().second;
        pq.pop();
        if(check.find({ca[x], {cb[x], cc[x]}}) != check.end()) continue;
        a.push_back(ca[x]);
        b.push_back(cb[x]);
        c.push_back(cc[x]);
        check.insert({ca[x], {cb[x], cc[x]}});


    }
    pq = priority_queue<pair<int, int>>();
    for(int i = 0; i < n; i++){

        pq.push({cc[i], i});

    }
    repeat(3){
        int x = pq.top().second;
        pq.pop();
        if(check.find({ca[x], {cb[x], cc[x]}}) != check.end()) continue;

        a.push_back(ca[x]);
        b.push_back(cb[x]);
        c.push_back(cc[x]);
        check.insert({ca[x], {cb[x], cc[x]}});

    }
    int ans = 0;
    n = a.size();
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             ans = max(ans, a[i] + b[j] + c[k]);
    //             ans = max(ans, a[i] + c[j] + b[k]);
    //             ans = max(ans, b[i] + a[j] + c[k]);

    //             ans = max(ans, b[i] + c[j] + a[k]);
    //             ans = max(ans, c[i] + a[j] + b[k]);
    //             ans = max(ans, c[i] + b[j] + a[k]);

    //         }
    //     }
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j and i != k and j != k){
                    ans = max(ans, a[i] + b[j] + c[k]);
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " " << b[i] << " " << c[i] << ENDL;
    //  }
    cout << ans << ENDL;
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) solve();
    


    endd
}



