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


void solve(){
    int n, k, a, b;
    cin>>n>>k>>a>>b;
    vector<pair<int, int> > large;
    vector<pair<int, int> > all_city(n);
    pair<int, int> A, B;
    for(int i = 0; i < n; i++){
        cin >> all_city[i].first >> all_city[i].second;
        if(i + 1 == a){
            A = all_city[i];
        }
        if(i + 1 == b){
            B = all_city[i];
        }
        if(i < k){
            large.push_back(all_city[i]);
        }
    }
    int ans1 = abs(A.first - B.first) + abs(A.second - B.second);
    int a_to_bonus = ans1;
    int b_to_bonus = ans1;
    for(int i = 0; i < large.size(); i++){
        a_to_bonus = min(a_to_bonus, abs(A.first - large[i].first) + abs(A.second - large[i].second));
        b_to_bonus = min(b_to_bonus, abs(B.first - large[i].first) + abs(B.second - large[i].second));
    }
   
    cout << min(ans1, a_to_bonus + b_to_bonus) << ENDL;


}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    
    int n;
    cin>>n;
    while(n--) solve();


    endd
}