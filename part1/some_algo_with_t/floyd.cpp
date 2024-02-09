#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    int m;
    cin >> m;
    // vector<vector<int>> massive(n + 1, vector<int>(n + 1, INT_MAX));
    int massive[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            massive[i][j] = INT_MAX;
        }
    }
    // 1 
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        massive[a][b] = cost;
        massive[b][a] = cost;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                massive[i][j] = min(massive[i][j], massive[i][k] + massive[k][j]);
            }
        }
    }
    cout << massive[1][n];
    // midterm sort merge O(n)

    // FLOYD - O(n * n * n) 
    // Deiks  O((n + m) * log(n))  || O(n * n) 
    // Ford - O(n * n) -> N * N 


}