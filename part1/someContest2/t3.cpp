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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int cntD = 0;
    int cntR = 0;
    string s;cin>>s;
    vector<int> bolean(n);
    while(true){
        int D = 0;
        int R = 0;
        repeat(n){
            if(bolean[_]) continue;
            if(s[_] == 'D' and cntD > 0){
                cntD--;
                bolean[_] = true;
            } else if(s[_] == 'R' and cntR > 0){
                cntR--;
                bolean[_] = true;
            } else if(s[_] == 'R'){
                cntD++;
            } else if(s[_] == 'D'){
                cntR++;
            }
            if(s[_] == 'R') R++;
            else D++;
        }
        if(R == 0){
            cout << "D";
            return 0;
        } else if(D == 0){
            cout << "R";
            return 0;

        }
    }
    // if(cntD > cntR){
    //     cout << "R";
    // } else if(cntD < cntR){
    //     cout << "D";
    // }
    


    endd
}