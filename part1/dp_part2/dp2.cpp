#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int MAXX = 300000;
vector<int> piramida(MAXX + 3, 0);
vector<int> w(MAXX + 3, 0);
vector<int> dp(MAXX + 1, INT16_MAX);
    

void solve(){
    int n;
    cin >> n;   
    cout << dp[n] << ENDL;
}

signed main(){
    
    goodluck

    w[1] = 1;
    for(int i = 2; i <= MAXX + 1; i++){
        w[i] = w[i - 1] + i;
    }
    piramida[1] = w[1];
    for(int i = 2; i <= MAXX + 1; i++){
        piramida[i] = piramida[i - 1] + w[i];
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= MAXX; i++){
        for(int j = 1; j <= i; j++){
            if(piramida[j] <= i){
                dp[i] = min(dp[i], dp[max(0, i - piramida[j])] + 1);
            } else{
                break;
            }
        }
    }

    int n;
    cin >> n;
    while(n--) solve();

    
    


    endd
}