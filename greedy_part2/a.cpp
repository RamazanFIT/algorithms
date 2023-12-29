#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int ans = 0;




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > mario;

    vector<vector<int> > w(n + 2, vector<int>(m + 2));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> w[i][j];
            if(w[i][j] == 2){
                mario.push_back(make_pair(i, j));
            }
        }
    }
    
    while(true){

        vector<pair<int, int> > mario2;
        for(int i = 0; i < mario.size(); i++){
            int x = mario[i].first;
            int y = mario[i].second;
            if(w[x - 1][y] == 1){
                mario2.push_back(make_pair(x - 1, y));
                w[x - 1][y] = 2;
            }
            if(w[x + 1][y] == 1){
                mario2.push_back(make_pair(x + 1, y));
                w[x + 1][y] = 2;
            }
            if(w[x][y - 1] == 1){
                mario2.push_back(make_pair(x, y - 1));
                w[x][y - 1] = 2;
            }
            if(w[x][y + 1] == 1){
                mario2.push_back(make_pair(x, y + 1));
                w[x][y + 1] = 2;
            }
        }
        mario = mario2;
        if(mario.size() == 0){
            break;
        }
        ans++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // cin >> w[i][j];
            if(w[i][j] == 1){
                // mario.push_back(make_pair(i, j));
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans << ENDL;
    endd
}