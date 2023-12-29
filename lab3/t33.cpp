#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

int bin_search_vverx(vector<int> & massive, int target){
    int left = 0;
    int right = massive.size();
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(massive[mid] > target){
            right = mid;
        } else if(massive[mid] < target){
            left = mid;
        } else{
            right = mid;
            break;
        }
    }
    return right;
}

int bin_search_vniz(vector<int> & massive, int target){
    int left = 0;
    int right = massive.size();
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(massive[mid] > target){
            right = mid;
        } else if(massive[mid] < target){
            left = mid;
        } else{
            left = mid;
            break;
        }
    }
    return left;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];
    massive.push_back(__LONG_LONG_MAX__);
    massive.push_back(0);
    sort(all(massive));
    // for(int i = 1; i <= n; i++){
    //     cout << massive[i] << " ";
    // }
    // cout << ENDL;
    for(int i = 0; i < q; i++){
        int ans = 0;
        int z = 4;
        vector<int> tmp(z);
        bool flag = false;
        for(int j = 0; j < z; j++) cin >> tmp[j];
        if((tmp[2] >= tmp[0] and tmp[2] <= tmp[1]) or (tmp[3] >= tmp[0] and tmp[3] <= tmp[1]) or
            (tmp[0] >= tmp[2] and tmp[0] <= tmp[3]) or (tmp[1] >= tmp[2] and tmp[1] <= tmp[3])){
            flag = true;
        } 
        sort(all(tmp));
        int x1, x2, y1, y2;
        x1 = tmp[0];
        x2 = tmp[1];
        y1 = tmp[2];
        y2 = tmp[3];
        
        int z1 = INT_MIN;
        int z2 = INT_MAX;
        if(flag){
            z1 = x2 + 1;
            z2 = y1;
            y1++;
        }
        
        int index1 = bin_search_vniz(massive, x2);

        while(index1 + 1 < n and massive[index1] == massive[index1 + 1]){
            index1++;
        }
        int index2 = bin_search_vverx(massive, x1);

        while(index2 - 1 >= 0 and massive[index2] == massive[index2 - 1]){
            index2--;
        }
        
        
        int index3 = bin_search_vniz(massive, y2);

        while(index3 + 1 < n and massive[index3] == massive[index3 + 1]){
            index3++;
        }
        int index4 = bin_search_vverx(massive, y1);
    
        while(index2 - 1 >= 0 and massive[index4] == massive[index4 - 1]){
            index4--;
        }
        int index5 = bin_search_vniz(massive, z2);

        while(index5 + 1 < n and massive[index5] == massive[index5 + 1]){
            index5++;
        }
        int index6 = bin_search_vverx(massive, z1);
    
        while(index6 - 1 >= 0 and massive[index6] == massive[index6 - 1]){
            index6--;
        }
        if(index1 >= index2)
        ans += index1 - index2 + 1;
        if(index3 >= index4)
        ans += index3 - index4 + 1;
        if(index5 >= index6)
        ans += index5 - index6 + 1;
        cout << ans << ENDL;

        
        
        
       
    }
    


    endd
} 