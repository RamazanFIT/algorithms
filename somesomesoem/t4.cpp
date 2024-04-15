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

bool check(int n){
    // while(n > 0){
    //     cout << n % 10 << " ";
    //     if(((n%10) == 1) or ((n %10) == 0)) return false;
    //     n /= 10;
    // }
    // return true;fe
    string s = to_string(n);
    for(auto it : s){
        if((it != '1') and (it != '0')) return false;
    }
    return true;
}

set<int> massive = {1 ,10 ,11 ,100 ,101 ,110 ,111 ,1000 ,1001 ,1010 ,1011 ,1100 ,1101 ,1110 ,1111 ,10000 ,10001 ,10010 ,10011 ,10100 ,10101 ,10110 ,10111 ,11000 ,11001 ,11010 ,11011 ,11100 ,11101 ,11110 ,11111 ,100000 ,100001};
bool rec(int n){
    // cout << "fe";
    cout << n << " ";
    if(massive.find(n) != massive.end()) return true;
    for(auto it : massive){
        if(n % it == 0 and it != 1){
            if(massive.find(n / it) != massive.end()){
                // cout << "YES" << ENDL;
                return rec(n / it);
            }
            if(check(n)){
                // cout << "YES" << ENDL;
                // return true;
                return true;
            }
            // cout << n / it << " ";
        }
    }
    return false;
}
void solve(int ccase){
    // int n = (1e5 + 7);
    
    // for(int i = 1; i <= n; i++){
    //     if(check(i)){
    //         cout << i << " ,";
    //     }
    // }
    // cout << check(101010201010);
    int n;get(n);
    set<int> massive = {10 ,11 ,100 ,101 ,110 ,111 ,1000 ,1001 ,1010 ,1011 ,1100 ,1101 ,1110 ,1111 ,10000 ,10001 ,10010 ,10011 ,10100 ,10101 ,10110 ,10111 ,11000 ,11001 ,11010 ,11011 ,11100 ,11101 ,11110 ,11111 ,100000 ,100001};
    while(n > 1){
        bool flag = true;
        if(massive.find(n) != massive.end()){
            cout << "YES" << ENDL;
            return;
        }
        for(auto it : massive){
            if(n % it == 0){
                n /= it;
                flag = false;
            }
        }
        if(flag){
            cout << "NO" << ENDL;
            return;
        }
    }
    cout << "YES" << ENDL;
}

signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    freopen("std2.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}