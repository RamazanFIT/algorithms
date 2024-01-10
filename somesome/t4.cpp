#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define skip continue;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void SOLVE(){
    int n;
    cin >> n;
    int sum = 0;
    int cnt = 0;
    int dcnt = 0;
    for(int i = 0 ; i< n ; i++){
        int a;
        cin >> a;
        sum += a;
        int left, right, s;

        if(a % 2 == 0) cnt++;
        else dcnt++;
        left = cnt;
        right = dcnt;
        s = sum;
        if(right == 0  or right == 2 or i == 0){
            cout << s << " ";
            skip
        }
        if(right == left and i > 0){
            cout << s - left << " ";
            skip
        }
        s -= (right / 3);
        if(right % 3 == 1){
            s--;
        }
        cout << s << " ";
    }
    cout << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    repeat(t) SOLVE();
    


    endd
}