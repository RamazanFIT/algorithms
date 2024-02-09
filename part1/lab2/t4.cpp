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
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    unordered_map<int, int> mapa;
    priority_queue<int> pq;
    int max_ = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        mapa[a]++;
        max_ = max(max_, mapa[a]);
    }
    for(auto it : mapa){
        if(it.second == max_){
            pq.push(it.first);
        }
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << ENDL;
    


    endd
}