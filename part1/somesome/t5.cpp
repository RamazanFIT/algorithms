#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    int l;
    cin >> n >> l;
    vector<int> vi(n);
    for(int i = 0; i < n; i++){
        cin >> vi[i];
    }
    vi.pb(0);
    vi.pb(l);
    sort(all(vi));
    double dx = vi[1] * 2;
    dx = max(int(dx), (vi[vi.size() - 1] - vi[vi.size() - 2]) * 2);
    for(int i = 1; i < vi.size(); i++){
        // dx = max(dx, vi[i] - vi[i - 1]);
        if(vi[i] - vi[i - 1] > dx){
            dx = vi[i] - vi[i - 1];
        }
    } //0 1 2 3 4 5 6
    
    cout << setprecision(9) << fixed << dx / 2;
    


    endd
}