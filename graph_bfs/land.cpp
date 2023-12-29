#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int ans = 0;

void dfs(vector<vector<char> > &massive, int i, int j){
    ans++;

    massive[i][j] = '#';
    if(massive[i + 1][j] == '.'){
        dfs(massive, i + 1, j);
    }
    if(massive[i][j + 1] == '.'){
        dfs(massive, i, j + 1);
    }
    if(massive[i - 1][j] == '.'){
        dfs(massive, i - 1, j);
    }
    if(massive[i][j - 1] == '.'){
        dfs(massive, i, j - 1);
    }
}
int test = 1;
void solve(){
    int n, m;
    cin >> m >> n;
    int x, y;
    vector<vector<char> > massive(n + 2, vector<char>(m + 2, '#'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> massive[i][j];
            if(massive[i][j] == '@'){
                x = i;
                y = j;
            }
        }
    }
    dfs(massive, x, y);
    cout << "Case " << test++ << ": "<< ans << ENDL;
    ans = 0;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) 
    solve();    


    endd
}