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
    int n;
    cin>>n;
    deque<int> deq;
    for(int i = n; i >= 1; i--){
        deq.push_front(i);
        for(int j = 0; j < i; j++){
            deq.push_front(deq.back());
            deq.pop_back();
        }
    }
    for(auto i : deq)
        cout<<i<<" ";
    cout<<ENDL;}





signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);
    int n;
    cin>>n;
    while(n--) solve();
    
    


    endd
}