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
int mod = 1e9 + 7;
map<int, int> mapa;
int rec(int check, int k, int cnt = 0){
    if(cnt >= 32) return 1;
    if(k == 1){
        return check % mod;
    }
    // if(check == (rec(check, k - 1) ^ (rec(check, k - 1) / 2))){
    //     return check;
    // } else{
    //     return -1;
    // }
    mapa[k - 1] = rec(check % mod, (k - 1ll) % mod, cnt + 1);
    int bb = (mapa[k - 1] / 2ll);
    mapa[k] =  (mapa[k - 1] ^ bb) % mod;
    return mapa[k];
}

void solve(int ccase){
    // for(int j = 1; j <= 1000; j++){
    //     cout << "FOr: " << j << ENDL;
    int k;
    cin >> k;
    k++;
        int cnt = 0;
        for(int i = 0; i <= 20000; i++){
            // int x = (i ^ (i / 2)); // 2
            // int y = (x ^ (x / 2)); // 3 
            // int z = (y ^ (y / 2)); // 4
            // int a = (z ^ (z / 2)); // 5
            // int b = (a ^ (a / 2)); // 5
            // if(i == (x ^ (x / 2))){
            //     cout << i << " ";
            // }
            // cout << "TIme: " << i << ENDL;
            // cout << rec(i, 3) << ENDL;
            int x = rec(i, k, 0);
            // if(x != -1){
            //      cout << "TIme: " << i << ENDL;
            // }
          
            if(x == i){
                // cout << i << " ";
                cnt++;
            }


        }
        cout << cnt - 1 << ENDL;
    // }
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