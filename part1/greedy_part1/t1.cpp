// #include <bits/stdc++.h>
// #define ENDL "\n"
// #define ff first 
// #define ss second  
// #define all(x) (x).begin(), (x).end()
// #define endd return 0;
// #define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
// using ll = long long;
// using namespace std;

// signed main(){
    
//     goodluck
//     // freopen("std.in", "r", stdin);
//     // freopen("std.out", "w", stdout);

//     int n;
//     int k;
//     cin >> n >> k;
//     vector<int> massive(n);
//     map<int, int> mapa;
//     vector<bool> flag(n, 0);

//     for(int i = 0; i < n; i++){
//         cin >> massive[i];
//         mapa[massive[i]]++;
//         if(massive[i] > k){
//             cout << "Impossible";
//             return 0;
//         }
//     }

//     int i = 0;
//     int ans = 0;
//     while(true){
//         int target = k - mapa.begin()->first;
//         // auto x = mapa.upper_bound(target);
//         // cout << x->first << ENDL;
//         auto x = NULL;
//         for(auto it = mapa.rbegin(); it != mapa.rend(); it++){
//             if(it->first <= target){
//                 it->
//             }
//         }
//         // if(x == mapa.end()) 
//         if(mapa.size() == 0) break;
//         if(x->first + mapa.begin()->first <= k){
//             // cout << "Impossible";
//             // return 0;
//             ans++;
//             mapa.begin()->second--;
//             x->second--;
//             if(mapa.begin()->second <= 0){
//                 mapa.erase(mapa.begin()->first);
//             }
//             if(x->second <= 0){
//                 mapa.erase(x->first);
//             }
//         } else if(mapa.begin()->first <= k){
//             ans++;
//             mapa.begin()->second--;
//             if(mapa.begin()->second <= 0){
//                 mapa.erase(mapa.begin()->first);
//             }
//         } 
//         // cout << ans << ENDL;

//     }
//     cout << ans;

//     endd
// }