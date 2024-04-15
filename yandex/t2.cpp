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
    // hellochild
    // helto<left><bspace>l<delete>ochilds<bspace>
    // hellochild
    string s;get(s);
    string a, b;
    string st;get(st);
    int n = st.size();
    st += "#####";
    int i = 0;
    int j = 0;
    bool flag = false;
    while(true){
        if(st[i] == '<') {flag = true;j = i + 1;i++;continue;}
        if(st[i] == '>' and flag){
            int type;
            // 1 - left 
            // 2 - right 
            // 3 - bspace 
            // 4 - delete 
            if(st[j] == 'l') type = 1;
            if(st[j] == 'r') type = 2;
            if(st[j] == 'b') type = 3;
            if(st[j] == 'd') type = 4;

            if(type == 1 and a.size() >= 1){
                b = a[a.size() - 1] + b;
                a.pop_back();
            } else
            if(type == 2 and b.size() >= 1){
                a += b[0];
                string tmp = "";
                for(int m = 1; m < b.size(); m++){
                    tmp += b[m];
                }
                b = tmp;
            } else 
            if(type == 3 and a.size() >= 1){
                a.pop_back();
            } else 
            if(type == 4 and b.size() >= 1){
                string tmp = "";
                for(int m = 1; m < b.size(); m++){
                    tmp += b[m];
                }
                b = tmp;
            }
            i++;
            flag = false;
            continue;
        }
        if(flag) {
            i++;
            continue;
        }
        if(i >= n) break;
        a += st[i];
        i++;
    }
    string tmp = a + b;
    if(tmp == s){
        put("Yes");
    } else{
        put("No");
    }
    // put("a: ", a, " b: ", b);
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