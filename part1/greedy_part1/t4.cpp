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


bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if((a.ss.ff * b.ss.ss) > (a.ss.ss * b.ss.ff)){
        return false;
    } else if((a.ss.ff * b.ss.ss) < (a.ss.ss * b.ss.ff)){
        return true;
    } else{
        if(a.ff < b.ff){
            return true;
        } else{
            return false;
        }
    }
    
}

void solve(int n){

    vector<pair<int, pair<int, int> > > massive(n);
    for(int i = 0; i < n; i++){
        massive[i].ff = i + 1;
        cin >> massive[i].ss.ff >> massive[i].ss.ss;
    }
    
    sort(all(massive), comp);

    for(auto it : massive){
        cout << it.ff << " ";
    } cout << ENDL;

}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int x;
    while(cin >> x){
        solve(x);
    }

    endd
}