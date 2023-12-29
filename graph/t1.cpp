#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n, m;
    cin>>n>>m;
    vector< set < int > > graph(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int max_ = 0;
    int min_ = INT_MAX;

    // vector<int> sorted;
    map<int, int> mapa;
    for(int i = 1; i < n + 1; i++){
        if(graph[i].size() > 1)
        // sorted.push_back(graph[i].size());
        mapa[graph[i].size()]++;
    }
    // sort(all(sorted));
    // cout << sorted[sorted.size() - 1] << " " << sorted[sorted.size() - 2] - 1 << ENDL;
    int x, y;
    for(auto it : mapa){
        max_ = max(max_, it.second);
        min_ = min(min_, it.second);
    }
    for(auto it : mapa){
        if(max_ == it.second){
            y = it.first;
        }
         if(min_ == it.second){
            x = it.first;
        }
    }
    cout << x <<  " " << y - 1 << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    
    


    endd
}