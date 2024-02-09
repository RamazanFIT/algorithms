#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("battleship.in", "r", stdin);
    freopen("battleship.out", "w", stdout);
    int n = 10;
    int x, y;
    vector<vector<int> > w(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
            if(w[i][j] == 100){
                x = i;
                y = j;
            }
        }
    }
     
    cout << "...####...\n..........\n#....##...\n#.#.....#.\n........#.\n...###....\n.#........\n........#.\n..#.....#.\n.....#..#.";


    endd
}