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
    int X;
    cin >> X;
    
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int el;
        cin>>el;
        pq.push(el);
    }
    int cnt = 0;
    while(true){
        if(X == 1){
            int sum =0;
            while(!pq.empty()){
                sum += pq.top();
                pq.pop();
            }
            cout << cnt + sum << ENDL;
            return 0;
        }
        int t = pq.top();
        pq.pop();
        if(t == 0) break;
        pq.push(max(0ll, t - X));
        if(X % 2 == 0){
            X /= 2;
        } else{
            X /= 2;
            X++;
        }
        cnt++;
    }
    cout << cnt;
    
    


    endd
}