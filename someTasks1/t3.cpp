/* 
    Bismillah 
 لا إله إلا الله محمد رسول الله
 Al'-Phatixa
 بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 ٱلْحَمْدُ لِلَّهِ رَبِّ ٱلْعَٰلَمِينَ
 ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 مَٰلِكِ يَوْمِ ٱلدِّينِ
 إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ
 ٱهْدِنَا ٱلصِّرَٰطَ ٱلْمُسْتَقِيمَ
 صِرَٰطَ ٱلَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ ٱلْمَغْضُوبِ عَلَيْهِمْ وَلَا ٱلضَّآلِّينَ
*/
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define FORW(leftb,rightb,way) for(int i = leftb; i < rightb; i+=way)
#define FOR(leftb,rightb) for(int i = leftb; i < rightb; i+=1)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;

using ll = long long;
using namespace std;

void solve(int ccase){
    int n;
    get(n);
    int l;
    get(l);
    vii a(n), b(n);
    repeat(n){
        cin >> a[_] >> b[_];
    }
    // vii c;
    vector<pair<int, int>> c;
    for(int i = 0; i < n; i++){
        // c.pb(a[i] + abs(b[i + 1] - b[i]));
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            c.pb({a[i] + abs(b[j] - b[i]), i});
            
        }
    }
    int cnt = 0;
    int x = 0;
    sort(all(c));
    vii flag(n);
    for(int i = 0; i < c.size(); i++){
        if(flag[c[i].ss]) continue;
        if(x + c[i].ff <= l){
            x += c[i].ff;
            cnt++;
            flag[c[i].ss] = 1;
        } else{
            break;
        }
    }
    cout << cnt << ENDL;
    // print(c);
    for(auto it : c){
        cout << it.ff << " " << it.ss << ENDL;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}