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

    map<int, set<int>> mapax_;
    map<int, set<int>> mapay_;
    map<pair<int, int>, set<pair<int, int>>> mapaz1_;
    map<pair<int, int>, set<pair<int, int>>> mapaz2_;

    vector<pair<int, int>> v(n);
    repeat(n){
        get(v[_].ff, v[_].ss);
    }
    repeat(n){
        // int x, y;get(x, y);
        int x = v[_].ff;
        int y = v[_].ss;
        int z = min(x, y);
        int zz = max(x, y);
        if(_ % 2 == 0){
            
            mapax[x].insert(y);
            mapay[y].insert(x);
            mapaz1[{x - y, 0}].insert({x, y});
            mapaz2[{0, x + y}].insert({y, x}); // (y, x)

            bool flag = true;
            int last = 0;
            int cnt = 0;
            for(auto it : mapax[x]){
                if(flag){
                    flag = false;
                    last = it;
                    continue;
                }
                if(it - last == 1){
                    cnt++;
                    last = it;
                } else{
                    last = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "First" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }
            flag = true;
            cnt = 0;
            for(auto it : mapay[y]){
                if(flag){
                    flag = false;
                    last = it;
                    continue;
                }
                if(it - last == 1){
                    cnt++;
                    last = it;
                } else{
                    last = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "First" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }
            cnt = 0;
            flag = true;
            pair<int, int> lastt;
            for(auto it : mapaz1[{x - y, 0}]){
                if(flag){
                    flag = false;
                    lastt = it;
                    continue;
                }
                if(abs(it.ff - lastt.ff) == 1 and abs(it.ss - lastt.ss) == 1){
                    cnt++;
                    lastt = it;
                } else {
                    lastt = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "First" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }

            cnt = 0;
            flag = true;
            for(auto it : mapaz2[{0, x + y}]){
                if(flag){
                    flag = false;
                    lastt = it;
                    continue;
                }
                if(abs(it.ff - lastt.ff) == 1 and abs(it.ss - lastt.ss) == 1){
                    cnt++;
                    lastt = it;
                } else {
                    lastt = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "First" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }



        } else{
            mapax_[x].insert(y);
            mapay_[y].insert(x);
            mapaz1_[{x - y, 0}].insert({x, y});
            mapaz2_[{0, x + y}].insert({y, x}); // (y, x)


            bool flag = true;
            int last = 0;
            int cnt = 0;
            for(auto it : mapax_[x]){
                if(flag){
                    flag = false;
                    last = it;
                    continue;
                }
                if(it - last == 1){
                    cnt++;
                    last = it;
                } else{
                    last = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "Second" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }
            flag = true;
            cnt = 0;
            for(auto it : mapay_[y]){
                if(flag){
                    flag = false;
                    last = it;
                    continue;
                }
                if(it - last == 1){
                    cnt++;
                    last = it;
                } else{
                    last = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "Second" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }
            cnt = 0;
            flag = true;
            pair<int, int> lastt;
            for(auto it : mapaz1_[{x - y, 0}]){
                if(flag){
                    flag = false;
                    lastt = it;
                    continue;
                }
                if(abs(it.ff - lastt.ff) == 1 and abs(it.ss - lastt.ss) == 1){
                    cnt++;
                    lastt = it;
                } else {
                    lastt = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "Second" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }

            cnt = 0;
            flag = true;
            for(auto it : mapaz2_[{0, x + y}]){
                if(flag){
                    flag = false;
                    lastt = it;
                    continue;
                }
                if(abs(it.ff - lastt.ff) == 1 and abs(it.ss - lastt.ss) == 1){
                    cnt++;
                    lastt = it;
                } else {
                    lastt = it;
                    cnt = 0;
                }
                if(cnt == 4 and _ == n - 1){
                    cout << "Second" << ENDL;
                    return;
                } else if(cnt == 4){
                    cout << "Inattention" << ENDL;
                    return;
                }
            }


        }
        
    }
    cout << "Draw" << ENDL;

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