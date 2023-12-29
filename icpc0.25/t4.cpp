#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, int> mapa;
    vector<int> massive(n);
    vector<int> massive2(n);

    int el = -1;
    // vector<int>
    // flag = false;
    for(int i = 0; i < n; i++){
        cin >> massive[i];

        mapa[massive[i]]++;
        if(mapa[massive[i]] >= 2){
            el = massive[i];
        }
    }   
    vector<pair<int, int> > f;
    for(auto it : mapa){
        f.push_back(make_pair(it.second, it.first));
        // cout << it.first << " " << it.second << ENDL;
    }
    sort(f.rbegin(), f.rend());

    // auto it = mapa.end();
    // it--;
    if(mapa.size() == 1 and f[0].ff >= 4){
        cout << -1 << ENDL;
        return;
    }
    if(f[0].first >= 3){
        // el = it->first;
        el = f[0].second;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(el == massive[i]){
                if(cnt == 0){
                    massive2[i] = 1;
                } else if(cnt == 1){
                    massive2[i] = 3;
                } else if(cnt == 2){
                    massive2[i] = 2;
                } else{
                    massive2[i] = 1;
                }
                cnt++;
            }
        }
        for(int i = 0; i < n; i++){
            if(massive2[i] == 0){
                cout << 1 << " ";
            } else{
                cout << massive2[i] << " ";
            }
        }
        cout << ENDL;
    } else{
        int a = f[0].first;
        int a_a = f[0].ss;
        
        // it--;
        int b_b = f[1].ss;
        int b = f[1].first;
        // cout << a << " " << b << ENDL;
        if(b < 2 or a < 2){
            cout << -1 << ENDL;
            return;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(a_a == massive[i]){
                if(cnt1 == 0){
                    massive2[i] = 1;
                } else if(cnt1 == 1){
                    massive2[i] = 3;
                }  else{
                    massive2[i] = 1;
                }
                cnt1++;
            }
            if(b_b == massive[i]){
                if(cnt2 == 0){
                    massive2[i] = 1;
                } else if(cnt2 == 1){
                    massive2[i] = 3;
                }  else{
                    massive2[i] = 1;
                }
                cnt2++;
            }
        }
        for(int i = 0; i < n; i++){
            if(massive2[i] == 0){
                cout << 1 << " ";
            } else{
                cout << massive2[i] << " ";
            }
        }
        cout << ENDL;
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();
    


    endd
}