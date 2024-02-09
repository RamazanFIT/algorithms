#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vector<int> power(100);
int p = 31;

int get_hash(string s){
    int hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash += (s[i] - 'a' + 1) * power[i];
    }
    return hash;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    power[0] = 1;
    for(int i = 1; i < 100; i++){
        power[i] = power[i - 1] * p;
    }
    string s, a;
    cin >> s >> a;
    int hash = get_hash(a);
    int check = 0;
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        tmp += s[i];
    }
    check = get_hash(tmp);

    int ans = 0;
    if(check == hash){
        ans++;
    }
    for(int i = a.size(); i < s.size(); i++){
        check -= (s[i - a.size()] - 'a' + 1);
        check /= p;
        check += power[a.size() - 1] * (s[i] - 'a' + 1);
        if(check == hash){
            // ans++;
            string tmp = "";
            for(int j = i - a.size() + 1; j <= i; j++){

                tmp += s[j];
            }
            if(tmp == a){
                ans++;
            }
        }
    }
    cout << ans;
    // Best case O(n + m) 
    // Worth case O(n * m)

    endd
}