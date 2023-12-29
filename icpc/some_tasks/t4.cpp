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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    w[1] = 1;
    for(int i = 2; i <= MAXX + 1; i++){
        w[i] = w[i - 1] + i;
    }
    piramida[1] = w[1];
    for(int i = 2; i <= MAXX + 1; i++){
        piramida[i] = piramida[i - 1] + w[i];
    }
    int n;
    cin >> n;
    int ans = INT_MAX;
    vector<vector<int> > backpack(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(piramida[i] <= j){
                int ostatok = j - piramida[i];
                backpack[i][j] = max(backpack[i - 1][ostatok] + piramida[i], backpack[i - 1][j]); 
            } else{
                backpack[i][j] = backpack[i - 1][j];
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     if(backpack[i][n] == n){
    //         ans = i;
    //         break;
    //     }
    // }
    // cout << ans << ENDL;

    // cout << backpack[2][n];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << backpack[i][j] << " ";
        }
        cout << ENDL;
    }


    endd
}