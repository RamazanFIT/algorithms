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

int p = 2;
// int mod = 
vector<int> power(120);
int get_hash(string s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += (s[i] - 97) * power[i];
    }
    return sum;
}
signed main(){
    
    goodluck
    power[0] = 1;
    for(int i = 1; i < 120; i++){
        power[i] = power[i - 1] * p;
    }
   
    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 1; i <= n; i++){
        cin >> massive[i];
    }

    for(int i = 1; i <= n; i++){
        cout << char((massive[i] - massive[i - 1]) / power[i - 1] + 97);
    }
    


    endd
}