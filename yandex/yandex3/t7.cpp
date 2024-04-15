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
template<typename T>
void get(T &a) {std::cin >> a;}
template<typename T, typename... Args>
void get(T &a, Args&... args) {std::cin >> a;get(args...);}
template<typename T>
void put(const T &a) {std::cout << a;}
template<typename T, typename... Args>
void put(const T &a, const Args&... args) {std::cout << a;put(args...);}

using ll = long long;
using namespace std;

int L;

int multi(int x, int y){
    if(y <= 0) return 0;

    int sum = ((multi(x, y / 2) % L) * 2 % L);
    return (sum + x * (y % 2)) % L;
}



void solve(int ccase){
    int N;get(N, L);
    vector<int> D(N + 1);
    for(int i = 1; i <= N; i++){
        int el;
        cin >> el;
        D[i] = (D[i - 1] % L + el) % L;
    }
    // vii mass(4);repeat(4) cin >> mass[_];
    int d1, m1, y1, t1;get(d1, m1, y1, t1);

    int d, m, y;get(d, m, y);

    int ans = (multi((y - 1), D[N]) + d + D[m - 1]) % L;
    // put(ans); 
    // if(ans == 0){
    //     put(L);
    // } else{
    //     put(ans);
    // }
    int ans2 = (multi((y1 - 1), D[N]) + d1 + D[m1 - 1]) % L;
    // put(ans2, " ", t1);
    ans += (t1 - ans2);
    ans += L;
    ans %= L;

    if(ans == 0){
        put(L);
    } else{
        put(ans);
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