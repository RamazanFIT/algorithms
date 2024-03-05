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
#define int ll
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(int ccase){
    int n;
    cin >> n;
    // int cnt = 0;
    vii mass = {1, 3, 6, 10, 15};
    
    reverse(all(mass));
    // for(auto it : mass){
    //     if(it < n){
    //         cnt += n / it;
    //         n %= it;
    //     }
    // }
    // cout << cnt << ENDL;
    map<int, int> mapa = {
        {1, 1},
    {2, 2},
    {3, 1},
    {4, 2},
    {5, 3},
    {6, 1},
    {7, 2},
    {8, 3},
    {9, 2},
    {10, 1},
    {11, 2},
    {12, 2},
    {13, 2},
    {14, 3},
    {15, 1},
    {16, 2},
    {17, 3},
    {18, 2},
    {19, 3},
    {20, 2},
    {21, 2},
    {22, 3},
    {23, 3},
    {24, 3},
    {25, 2},
    {26, 3},
    {27, 3},
    {28, 3},
    {29, 4},
    {30, 2},
    {31, 3},
    {32, 4},
    {33, 4},
    {34, 4}
    };
    // for(int i = 0; i < 5; i++){
    //     for(int j = i + 1; j < 5; j++){
    //         cout << "{" << mass[i] + mass[j] << ", " << 2 << "}"; 
    //     }
    // }
    if(n > 34){
        int x = (n - 20) % 15 + 20;
        // cout << mapa[x] + (n - 20) / 15 << ENDL;
        cout << min(n / 15 + mapa[n % 15], mapa[x] + (n - 20) / 15) << ENDL;
    } else{
        cout << min(mapa[n], n / 15 + mapa[n % 15]) << ENDL;
    }

}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}