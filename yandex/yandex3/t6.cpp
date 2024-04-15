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

void solve(int ccase){
    int n;get(n);

    map<int, set<int>> mapax;
    map<int, set<int>> mapay;
    map<pair<int, int>, set<pair<int, int>>> mapaz1;
    map<pair<int, int>, set<pair<int, int>>> mapaz2;

    vector<pair<int, int>> v(n);
    repeat(n){
        get(v[_].ff, v[_].ss);
    }
    set<pair<int, int>> check;
    repeat(n){
        int x = v[_].ff;
        int y = v[_].ss;
        int z = min(x, y);
        int zz = max(x, y);

        check.insert(v[_]);
            
        mapax[x].insert(y);
        mapay[y].insert(x);
        mapaz1[{x - y, 0}].insert({x, y});
        mapaz2[{0, x + y}].insert({y, x}); 

    }

    int query;get(query);
    
    repeat(query){
        char type;int x, y;get(type, x, y);

        if(type == 'P'){
            int cnt = 0;
            // if(check.find({x - 1, y - 1}) != check.end()) cnt++;
            if(check.find({x + 1, y + 1}) != check.end()) cnt++;
            // if(check.find({x + 1, y - 1}) != check.end()) cnt++;
            if(check.find({x - 1, y + 1}) != check.end()) cnt++;
            put(cnt, ENDL);
        } else 
        if(type == 'K'){
            int cnt = 0;
            if(check.find({x - 1, y + 2}) != check.end()) cnt++;
            if(check.find({x - 1, y - 2}) != check.end()) cnt++;
            if(check.find({x + 1, y + 2}) != check.end()) cnt++;
            if(check.find({x + 1, y - 2}) != check.end()) cnt++;

            if(check.find({x - 2, y + 1}) != check.end()) cnt++;
            if(check.find({x - 2, y - 1}) != check.end()) cnt++;
            if(check.find({x + 2, y + 1}) != check.end()) cnt++;
            if(check.find({x + 2, y - 1}) != check.end()) cnt++;
            put(cnt, ENDL);
        } else
        if(type == 'B'){
            int cnt = 0;
            cnt += mapaz1[{x - y, 0}].size();
            cnt += mapaz2[{0, x + y}].size();
            put(cnt, ENDL);
        } else
        if(type == 'R'){
            int cnt = 0;
            cnt += mapax[x].size();
            cnt += mapay[y].size();
            put(cnt, ENDL);
        } else{ // Q
            int cnt = 0;
            cnt += mapax[x].size();
            cnt += mapay[y].size();
            cnt += mapaz1[{x - y, 0}].size();
            cnt += mapaz2[{0, x + y}].size();
            put(cnt, ENDL);
        } 
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