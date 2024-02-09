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
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int nn;
    cin>>nn;
    vector<int> target(nn);
    for(auto & it : target) cin >> it;
    // for(auto it : target) cout << it <<  " ";
    int n, m;
    cin>>n>>m;
    vector<vector<int> > massive(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> massive[i][j];
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout <<  massive[i][j] << " ";
    //     }
    //     cout << ENDL;
    // }
    for(int i = 0; i < nn; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            
            int left = -1;
            int right = m;
            if((j +  1) % 2 == 0){
                while(right - left > 1){
                int middle = (right + left) / 2;
                if(target[i] == massive[j][middle]){
                    left = middle;
                    break;
                } else if(target[i] > massive[j][middle]){
                    left = middle;
                } else if(target[i] < massive[j][middle]){
                    right = middle;
                }
                }
                if(target[i] == massive[j][left]){
                    flag = false;
                    cout << j << " " << left << ENDL;
                    break;
                }
            } else{
                while(right - left > 1){
                    int middle = (right + left) / 2;
                    if(target[i] == massive[j][middle]){
                        right = middle;
                        break;
                    } else if(target[i] > massive[j][middle]){
                        right = middle;
                    } else if(target[i] < massive[j][middle]){
                        left = middle;
                    }
                }
                if(target[i] == massive[j][right]){
                    flag = false;
                    cout << j << " " << right << ENDL;
                    break;
                }
            }
        }
        if(flag){
            cout << -1 << ENDL;
        }
    }

    
    


    endd
}