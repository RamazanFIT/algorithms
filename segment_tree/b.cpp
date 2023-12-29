#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

long double Px, Py;
long double Ax, Ay;
long double Bx, By;


bool check(long double middle){
    
    if(sqrt((Px - Ax) * (Px - Ax) + (Py - Ay) * (Py - Ay)) <= middle){
        if(sqrt(( Ax) * (Ax) + (Ay) * (Ay)) <= middle){
            return true;
        } else if(sqrt((Bx) * (Bx) + (By) * (By)) <= middle){
            if(sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay)) <= 2 * middle){
                return true;
            }
        }
    }

    if(sqrt((Px - Bx) * (Px - Bx) + (Py - By) * (Py - By)) <= middle){
        if(sqrt(( Bx) * (Bx) + (By) * (By)) <= middle){
            return true;
        } else if(sqrt((Ax) * (Ax) + (Ay) * (Ay)) <= middle){
            if(sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay)) <= 2 * middle){
                return true;
            }
        }
    }

    return false;
}



void solve(){
    cin >> Px >> Py >> Ax >> Ay >> Bx >> By;
    long double left = 0.0;
    long double right = 1000 * 3;
     double ans = INT_MAX / 2;
    for(int i  = 0; i < 32; i++){
        long double middle = (right + left) / 2;
        if(check(middle)){
            ans = middle;
            right = middle;
        } else{
            left = middle;
        }
    }
    cout << setprecision(10) << ans << ENDL;
// 3.60555178485810756683349609375
// 3.60555178485810756683349609375
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();    


    endd
}