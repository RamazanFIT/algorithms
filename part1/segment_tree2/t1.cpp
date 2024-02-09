#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

const int mod = 1e9 + 7;
int p = 231;

int get(string s){
    int r = 0;
    int x = 1;
    for(int i = 0; i < s.size(); i++){
        r += ((s[i] - 'a' + 1) * x) % mod;
        r %= mod;
        x *= p;
        x %= mod;
    }
    return r;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string a = "fewgfewfweewfewfewfefuweb";
    string b = "fewqfqwfffewfewfewfewwfefwefewf";
    // vector<bool> bolean(a.size());
    do
    {
        if(get(a) == get(b)){
            cout << a << " " << b << ENDL;
            cout << get(a) << " " << get(b);
            return 0;
        }
    } while (next_permutation(all(b)));
    
    


    endd
}