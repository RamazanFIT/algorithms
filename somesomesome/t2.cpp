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
#define int ll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define FORW(leftb,rightb,way) for(int i = leftb; i < rightb; i+=way)
#define FOR(leftb,rightb) for(int i = leftb; i < rightb; i+=1)
#define print(massive) \
    for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;

using ll = long long;
using namespace std;

void solve(int ccase){
    vii mass;
    for(int  i= 1; i <= 6; i++) mass.pb(i);
    int n = mass.size();
    int a = 0;
    map<pair<int, int>, int> mapa;
    do
    {
        int x, y;
        x = mass[0];
        int cnt1 = 0;
        int cnt2 = 0;
        y = mass[n - 1];
        for(int i = 0; i < n; i++){
            if(x <= mass[i]){
                cnt1++;
                x = mass[i];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(mass[i] >= y){
                cnt2++;
                y = mass[i];
            }
        }
        // cout << a++ << " " << cnt1 << " " << cnt2 << ENDL;
        mapa[{cnt1, cnt2}]++;
    } while (next_permutation(all(mass)));
    for(auto it : mapa){
        cout << it.first.ff << " " << it.ff.ss << " " << it.ss << ENDL;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}