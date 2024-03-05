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
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;
using ll = long long;
using namespace std;


const int mxN = 1e6+6;

int mex(vector<int> v) {
    set<int> s;
    for (auto i: v)
        s.insert(i);
    for (int i = 0; i < mxN; i++) {
        if (s.find(i) == s.end()) return i;
    }
    return 0;
}

vii mask;
void solve(int ccase){
    int n;
    cin >> n;
    if(mask[n] > 0 or n >= 2000){
        cout << "first" << ENDL;
    } else{
        cout << "second" << ENDL;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    mask = vii(1e6 + 7);
    mask[3] = 1;
    for(int i = 4; i < 2000; i++){
        bool flag = true;
        int cnt = 0;
        vii v;
        for(int j = 1; j <= (i - 1) / 2; j++){
            // if(i < 10)
            // cout << i << " " << j << " " << i - j << ENDL;

            // if((mask[j] ^ mask[i - j]) == 0){
            //     flag = false;
            //     break;
            // }
            v.pb((mask[j] ^ mask[i - j]));
        }
        
        // if(flag){
            mask[i] = mex(v);
        // } else{
        //     mask[i] = i;
        // }
    }
    // for(int i = 1; i < 100; i++){
    //     cout << mask[i] << " " << i << ENDL;
    // }
    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}