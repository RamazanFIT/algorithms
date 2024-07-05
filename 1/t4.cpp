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
    int n;get(n)
    ;
    int k;get(k)
    ;
    
    deque <int>
    dq 
    ;
    repeat(n)  {
        int el 
        ;
        get(el)
        ;
        dq.pb(el);

    }
    int ans = 0 
    ;
    // bool flag = true;
    int flag = 1;
    while(!dq.empty()){
        // if(flag){
            // put(k, " ");
            if(k <= 0) break;
            int f = dq.front();
            int b = dq.back();
            flag ^= 1;
            int m = min(f, b);
            if(dq.size() == 1){
                if(m >= k) ans++;
                break;
            } else if(f == b){
                if(2 * m <= k){
                    dq.pop_back();
                    dq.pop_front();
                    k -= 2 * m;
                } else{
                    break;
                }
            } else if(2 * m <= k){
                if(m == f){
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_back(b - m);
                } else if(m == b){
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_front(f - m);
                }
                k -= 2 * m;
                
            } else{
                break;
            }
        // } else{

        // }
    }
    // put(n - dq.size());
    for(auto it : dq){
        put(it, " ");
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