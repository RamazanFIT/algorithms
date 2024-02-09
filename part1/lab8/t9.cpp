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


int mod = 1e9 + 7;
int p = 103;


int binpow(int x, int power){
    if(power == 1) return x % mod;
    else if(power == 0) return 0ull;
    int xx = binpow(x % mod, power / 2) % mod;
    if(power % 2 == 0){
        return (xx * xx) % mod;
    } else{
        return (((xx * xx) % mod) * (x % mod)) % mod;
    }
}




int get_hash(string a){
    int sum = 0;
    int power = 1;
    for(int i = 0; i < a.size(); i++){
        sum += ((power % mod) * (a[i] - 'a' + 1)) % mod;
        sum %= mod;
        if(sum < 0){
            sum += mod;
            sum %= mod;
        }
        power = (power % mod) * p;
    }
    // return ((sum % mod) + mod) % mod;
    if(sum < 0){
            sum += mod;
            sum %= mod;
    }
    return sum % mod;
    
    
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    vector<int> power(100);
    power[0] = 1;
    power[1] = p;
    for(int i = 2; i < 100; i++){
        power[i] = ((power[i - 1] % mod) * (p % mod)) % mod;
        if(power[i] < 0){
            power[i] += mod;
            power[i] %= mod;
        }
    }
    int ppp = binpow(p, mod - 2);
    while(true){
        int x;
        cin >> x;
        if(x == 0) break;

        // map<string, int> mapa;
        vector<string> massive(x);
        vector<int> massive2(x);
        vector<int> massive3(x);
        
        
        for(int i = 0; i < x; i++){
            cin >> massive[i];
            massive2[i] = get_hash(massive[i]);
        }
        string s;
        cin >> s;
        
        for(int i = 0; i < x; i++){
            string tmp = "";
            for(int j = 0; j < massive[i].size(); j++){
                tmp += s[j];
            }
            massive3[i] = get_hash(tmp);
        }
        int maximum = INT_MIN;
        vector<pair<string, int> > answer(x);
        for(int i = 0 ; i < x; i++){
            int cnt = 0;
            for(int j = massive[i].size(); j <= s.size(); j++){
               
                if(massive2[i] == massive3[i]){
                    // mapa[massive[i]]++;
                    cnt++;
                    // maximum = max(maximum, mapa[massive[i]]);
                    maximum = max(maximum, cnt);
                }
                massive3[i] -= (s[j - massive[i].size()] - 'a' + 1);
                
                massive3[i] = ((massive3[i] % mod) * ppp) % mod;
                massive3[i] = ((massive3[i] % mod) + (power[massive[i].size() - 1] % mod) * (s[j] - 'a' + 1)) % mod;
                if(massive3[i] < 0)
                massive3[i] = ((massive3[i] % mod) + mod) % mod;
            }
            answer[i] = make_pair(massive[i], cnt);
        }
        cout << maximum << ENDL;
        for(auto it : answer){
           
            if(maximum == it.second){
                cout << it.first << ENDL;
            }
        }

    }
    


    endd
}