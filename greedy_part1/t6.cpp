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
    priority_queue<int> pq;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        pq.push(-k);
    }
    while(pq.size() > 1){
        int f1 = -pq.top();
        pq.pop();
        int f2 = -pq.top();
        pq.pop();
        ans += f1 + f2;
        pq.push(-(f1 + f2));
    }
    cout << ans << ENDL;

    


    endd
}