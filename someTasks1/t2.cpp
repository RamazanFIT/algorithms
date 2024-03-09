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

void solve(int ccase){
    int n;
    cin >> n;
    vii mass(n);
    repeat(n) get(mass[_]);

    vii a(n), b(n);

    set<int> st;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        st.insert(mass[i]);
        if(st.find(cnt) == st.end()){
            a[i] = cnt;
        } else{
            while(st.find(cnt) != st.end()){
                cnt++;
            }
            a[i] = cnt;
        }
    }
    st.clear();
    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        st.insert(mass[i]);
        if(st.find(cnt) == st.end()){
            b[i] = cnt;
        } else{
            while(st.find(cnt) != st.end()){
                cnt++;
            }
            b[i] = cnt;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(a[i] == b[i + 1]){
            cout << 2 << ENDL;
            cout << 1 << " " << i + 1 << ENDL;
            cout << i + 1 + 1 << " " << n << ENDL;
            return;
        }
    }
    cout << -1 << ENDL;
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