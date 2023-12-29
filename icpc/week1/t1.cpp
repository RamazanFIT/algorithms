#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int k = n;
    vector<pair<int, int> > massive; 
    for(int i = 2; i < sqrt(n) + 1; i++){

        if(k % i == 0){
            int cnt = 0;
            while(k % i == 0){
                k /= i;
                cnt++;
            }
            massive.push_back(make_pair(i, cnt));
        }
    }
    if(k > 1){
        massive.push_back(make_pair(k, 1));
    }

    for(int i = 0; i < massive.size() - 1; i++){
        if(massive[i].second == 1){
            cout << massive[i].first << '*';
        } else{
            cout << massive[i].first << '^' << massive[i].second << "*";
        }
    }
    if(massive[massive.size() - 1].second == 1){
            cout << massive[massive.size() - 1].first << ENDL;
        } else{
            cout << massive[massive.size() - 1].first << "^" << massive[massive.size() - 1].second << ENDL;
        }
    


    endd
}