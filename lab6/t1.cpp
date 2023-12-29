#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    map<int, int> mapa;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mapa[a]++;
    }
    priority_queue<int> pq;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        if(mapa[a] > 0){
            // cout << a << " ";
            pq.push(-a);
            mapa[a]--;
        }
    }
    while(!pq.empty()){
        cout << -pq.top() << " ";
        pq.pop();
    }


    endd
}