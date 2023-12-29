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
    // freopen("justforfood.in", "r", stdin);
    // freopen("justforfood.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> countFoods(n);
   
    for(int i = 0; i < n; i++){
        cin >> countFoods[i];
        
    }

    sort(all(countFoods));

    int ans1 = 0;
    int ans2 = 0;
    int pos1 = 0;
    int pos2 = 0;
    for(int i = 0; i < n; i++){
        if(countFoods[i] <= n - i){
            ans1 = countFoods[i];
            pos1 = i;
        }
    }
    vector<int> m1 = countFoods;
    vector<int> m2 = countFoods;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = pos1; i > max(pos1 - m, -1); i--){
        m1[i]++;
        cnt1++;
    }
    for(int i = pos1 + 1; i < min(pos1 + 1 + (m - cnt1), n); i++){
        m1[i]++;
    }

    for(int i = pos1 - 1; i > max((pos1 - 1) - m, -1); i--){
        m2[i]++;
        cnt2++;
    }
    // for(int i = pos1 + 1; i < min(pos1 + 1 + (m - cnt2), n); i++){
    //     m2[i]++;
    // }
    sort(all(m1));
    sort(all(m2));
    for(int i = 0; i < n; i++){
        if(m1[i] <= n - i){
            ans1 = m1[i];

        }
    }
    for(int i = 0; i < n; i++){
        if(m2[i] <= n - i){
            ans2 = m2[i];

        }
    }
    cout << max(ans2, ans1) << ENDL;
    
    
    
    


    endd
}