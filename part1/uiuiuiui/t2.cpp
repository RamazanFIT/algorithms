// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int k;

bool inthat(int x){
    if(x >= 1 and x <= k){
        return true;
    } return false;
}

void solve(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    cin >> k;
    int cnt1 = 0, cnt2 = 0;
    set<int> s1, s2;
    repeat(n){
        int a;
        cin >> a;
        s1.insert(a);
    }
    repeat(m){
        int a;
        cin >> a;
        s2.insert(a);
    }
    set<int> check;
    for(auto it : s1){
        if(cnt1 >= k / 2) break;
        if(inthat(it) and s2.find(it) == s2.end()){
            cnt1++;
            check.insert(it);
        }
    }
    for(auto it : s2){
        if(cnt2 >= k / 2) break;

        if(inthat(it) and s1.find(it) == s1.end()){
            cnt2++;
            check.insert(it);
        }
    }
    if(cnt1 < k / 2){
        
        for(auto it : s1){
            if(cnt1 >= k / 2) break;

            if(inthat(it) and s2.find(it) != s2.end()){
                cnt1++;
                check.insert(it);
            }
        }
    }
    if(cnt2 < k / 2){
        for(auto it : s2){
            if(cnt2 >= k / 2) break;

            if(inthat(it) and s1.find(it) != s1.end() and check.find(it) == check.end()){
                cnt2++;
                check.insert(it);
            }
        }
    }

    if(cnt1 == k / 2 and cnt2 == k / 2) {
        cout << "YES" << ENDL;
    } else{
        cout << "NO" << ENDL;
    }

}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin >> n;
    repeat(n) solve();

    endd
}