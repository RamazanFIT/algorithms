#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    int aa = a;
    int bb = b;
    vector<int> answer;
    vector<int> answer2;

    while(a < b){
        a *= 2;
        answer.pb(a);
    }
    while(a != b){
        a--;
        answer.pb(a);
    }
    // cout << answer.size() << ENDL;
    // for(auto it : answer){
    //     cout << it << " ";
    // }
    
    if(aa > bb){
        while(aa > 1){
            if(aa <= (bb / 2)) break;
            a--;
            answer2.pb(a);
        }
        answer2.pb(aa * 2);
    }

    if(answer2.size() < answer.size() and answer2.size() != 0){
        cout << answer2.size() << ENDL;
        for(auto it : answer2){
            cout << it << " ";
        }
    } else{
        cout << answer.size() << ENDL;
        for(auto it : answer){
            cout << it << " ";
        }
    }


    endd
}