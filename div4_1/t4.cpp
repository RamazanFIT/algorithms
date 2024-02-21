// Bismillah 
// لا إله إلا الله محمد رسول الله
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int p[100];
int get(int x){
    int cnt = 0;
    while(x > 0){
        x /= 2;
        cnt++;
    }
    return cnt;
}
void solve(int ccase){
    int n;cin>>n;
    multiset<int> st;
    vector<int> massive;
    repeat(n){
        int a;
        cin >> a;
        st.insert(a);
        massive.pb(a);
    }
    int ans = 0;
    
    // for(int i = 0; i < n; i++){
    while(st.size() > 0){
        // int x = p[get(massive[i])] - 1;
        if(st.size() == 0) break;
        int i = 0;
        massive[i] = *(st.begin());
        int x = p[31] - 1;
        int y = (massive[i] ^ x);
        // cout << y << " " << massive[i] << ENDL;
        if(st.size() == 0) break;

        if((y == massive[i]) or st.find(y) == st.end()){
            ans++;
        if(st.size() == 0) break;

            st.erase(st.find(massive[i]));
        } else{
            ans++;
        if(st.size() == 0) break;

            st.erase(st.find(massive[i]));
            // cout << y << ENDL;
            // if(st.find(y) != st.end())
        if(st.size() == 0) break;

            st.erase(st.find(y));
        }
        if(st.size() == 0) break;
    }
    cout << ans << ENDL;
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    p[0] = 1;
    for(int i = 1; i < 35; i++){
        p[i] = p[i - 1] * 2;
    }
    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}