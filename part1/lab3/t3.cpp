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
    freopen("std.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];
    massive.push_back(__LONG_LONG_MAX__);
    massive.push_back(-__LONG_LONG_MAX__);
    sort(all(massive));
    // cout << ENDL;
    // for(int i = 0; i < n; i++) cout << massive[i] << " ";
    // cout << ENDL;
    for(int i = 0; i < q; i++){
        int ans = 0;
        int z = 4;
        vector<int> tmp(z);
        for(int j = 0; j < z; j++) cin >> tmp[j];
        sort(all(tmp));
        int x1, x2, y1, y2;
        bool flag = true;
        x1 = tmp[0];
        x2 = tmp[1];
        y1 = tmp[2];
        y2 = tmp[3];
        // if(x2 == y1){
        //     y1++;
        // }
        // if(y1 > y2){
        //     flag = false;
        // }
        int index1 = upper_bound(all(massive), x2) - massive.begin();
        while(index1 - 1 >= 0 and massive[index1] == massive[index1 - 1]){
            index1--;
        }
        int index2 = (lower_bound(all(massive), x1) - massive.begin());
        while(index2 <= n and massive[index2] == massive[index2 + 1]){
            index2++;
        }
        int index3 = upper_bound(all(massive), y2) - massive.begin();
        while(index3 - 1 >= 0 and massive[index3] == massive[index3 - 1]){
            index3--;
        }
        int index4 = (lower_bound(all(massive), y1) - massive.begin());
        while(index4 <= n and massive[index4] == massive[index4 + 1]){
            index4++;
        }
        // cout << x1 << " " << x2 << "  " << y1 << " " << y2 << ENDL;
        // ans += index1 - index2 + 1;
        
        // if(index1 == index4){
        //     while(index4 <= n and massive[index4] == massive[index4 + 1]){
        //         index4++;
        //     }
        // }
        // if(index4 <= index3)
        // ans += index3 - index4 + 1;
        // cout << index2 << " " << index1 << "  " << index4 << " " << index3 << ENDL;
        vector<int> kkk;
        kkk.push_back(index1);
        kkk.push_back(index2);
        kkk.push_back(index3);
        kkk.push_back(index4);
        sort(all(kkk));
        ans += kkk[1] - kkk[0] + 1;
        ans += kkk[3] - kkk[2] + 1; 
        cout << ans << ENDL;
    }
    


    endd
}