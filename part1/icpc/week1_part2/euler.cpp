#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0);
#define ll long long
using namespace std;

ll func_euler(pair<ll, ll> a){
    return(pow(a.first, a.second) - pow(a.first, a.second-1));
}





int main()
{
    boost
    ll in;
    while(true){
        cin >> in;
        if(in == 0) return 0;
        ll copy = in;
        vector<pair<ll, ll> > mass;
        for(int i=2;i<=sqrt(in);i++){
            if(in % i == 0){
                ll cnt = 0;
                while(in % i == 0){
                    in /= i;
                    cnt++;
                }
                pair<ll, ll> pairs(i, cnt);
                mass.emplace_back(pairs);
            }
        }
        if(in > 1){
            mass.emplace_back(pair<ll, ll>(in, 1));
        }
        ll all = 1;
        for(auto it : mass){
            all *= func_euler(it);
        }
        for(auto it : mass){
            cout << it.first << " " << it.second << endl;
        }
        cout << all << endl;
    }





}