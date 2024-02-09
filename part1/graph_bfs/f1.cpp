#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> w1(n + 1);
    vector<int> w2(m + 1);
    set<int> set1;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        w1[i] = w1[i - 1] + a;
        set1.insert(w1[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        int a;
        cin >> a;
        w2[i] = w2[i - 1] + a;
        if(set1.find(w2[i]) != set1.end()){
            cnt++;
        }
    }
    cout << cnt << ENDL;


    endd
}