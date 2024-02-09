#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int uint32_t
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

bool comp(pair<int, vector<int> > a, pair<int, vector<int> > b){
    if(a.ff > b.ff) return true;
    else if(a.ff < b.ff) return false;
   
    for(int i = 0; i < a.ss.size(); i++){
        if(a.ss[i] < b.ss[i]) return true;
        else if(a.ss[i] > b.ss[i]) return false;
    }
    return false;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector< pair < int, vector<int> > > massive(n, make_pair(0, vector<int>(m)));
    for(int i = 0; i < n; i++){
        int some_sum = 0;
        for(int j = 0; j < m; j++){
            cin >> massive[i].ss[j];
            some_sum += massive[i].ss[j];
        }
        massive[i].ff = some_sum;
    }
    sort(all(massive), comp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << massive[i].ss[j] << " ";
        }
        cout << ENDL;
    }
    


    endd
}