#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);

    // int x = 16814;
    // // set<string> check;
    // // repeat(x){
    // //     string s;
    // //     cin >> s;
    // //     check.insert(s);
    // // }
    // // cout << check.size();
    // // vector<set<string>> check(35);
    // set<string> s11, s22;
    // double cnt = 0;
    // map<string, int> mapa;
    // repeat(x){
    //     string s1, s2;
    //     int y;
    //     cin >> s1 >> s2 >> y;
    //     cout << "('" << s1 << "' ,'" << s2 << "' ," << y << " ), " << ENDL;
    //     // check[(s1[8] - '0') * 10 + (s1[9] - '0')].insert(s2);
    //     // if(((s1[8] - '0') * 10 + (s1[9] - '0')) == 1){
    //     //     s11.insert(s2);
    //     // }
    //     // if(((s1[8] - '0') * 10 + (s1[9] - '0')) == 2){
    //     //     s22.insert(s2);
    //     // }
    //     // if(y != 0)
    //         // cnt += y;
    //         // if(y != 0)
    //         // s11.insert(s2);
    //     // mapa[s2] += y;
        
    // }
    // // cout << s11.size();
    // // double sum = 0;
    // // for(auto it : mapa){
    // //     // if(s11.find(it) != s11.end()){
    // //     //     cnt++;
    // //     // }
    // //     sum += mapa[it.first];
    // // }
    // // cout << sum / double(mapa.size());
    // // // cout << sum / cnt;
    // // // cout << cnt / s11.size();
    // // // cout << double(s11.size()) / double(cnt);
    // // // cout << double(s11.size()) / double(x);
    // // // cout << double(cnt) / x;
    // endd

    int x = 158;
    map<int, int> mapa;
    vector<double> massive;
    repeat(x){
        // int x, y;
        // cin >> x;
        int y;
        cin >> y;
        repeat(2){
            string s;
            cin >> s;
        }
        int x;
        cin >> x;
        repeat(2){
            string s;
            cin >> s;
        }
        // mapa[y] = x;
        // cin >> y;
        // mapa[x] += y;
        massive.pb(x);
    }
    // sort(all(massive));
    // double sum = 0;
    // for(auto it : mapa){
    //     // sum += it.second;
    //     massive.pb(it.second);
    // }
    sort(all(massive));
    
    // cout << sum / mapa.size();
    if(massive.size() % 2 == 0){
        cout << (massive[massive.size() / 2] +  massive[massive.size() / 2 - 1] ) / 2;
    } else{
        cout << massive[massive[massive.size() / 2]];
    }
}