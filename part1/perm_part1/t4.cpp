#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int n, k;

void rec( vector<bool> & boolean){
    int w[k];
    int index = 0;
    for(int i = 0; i < n; i++){
        if(boolean[i]){
            w[index] = i + 1;
            index++;
        }
    }
    if(next_permutation(all(boolean))){
        rec(boolean);
    }
    for(int i = 0; i < k; i++){
        cout << w[i] << " ";
    } cout << ENDL;
    
}


signed main(){
    
    goodluck
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);


    cin >> n >> k;
    vector<bool> boolean(n, 0);
    for(int i = n - 1; i > n - 1 - k; i--){
        boolean[i] = true;
    }
    rec(boolean);
    // do
    // {
    //     for(int i = 0; i < n; i++){
    //         if(boolean[i]){
    //             cout << i + 1 << " ";
    //         }
    //     } cout << ENDL;
    // } while (next_permutation(all(boolean)));
    
    


    endd
}