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
#define get(a) cin >> a;

using ll = long long;
using namespace std;

int N = 100;

vii mass = vii(N);

void solve(int ccase){
    // 1 1 1 1 1 1 1

    // 0 0 0 0 0 0 0 

    int n;
    cin >> n;
    if(n < 52){
        if(mass[n]){
            cout << "White" << ENDL;
        } else cout << "Black" << ENDL;
        return;
    }
    vii a = {3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9};
    
    if(a[(n - 52) % 34]){
            cout << "White" << ENDL;
        } else cout << "Black" << ENDL;
    // cout << a[(n - 52) % 34] << ENDL;
}

int mex(set<int> a){
    int cnt=  0;
    while(a.find(cnt) != a.end()) cnt++;
    return cnt;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // 1 2 3 4 5 6

    mass[1] = 1;
    mass[2] = 1;
    mass[3] = 2;
    for(int i = 4; i < N; i++){
        set<int> a;
        a.insert(mass[i - 2]);

        for(int j = 2; j <= i - 1; j++){
            a.insert(mass[j - 2] ^ mass[i - j - 1]);
        }
        
        mass[i] = mex(a);
    }
    // for(int i = 1; i < N; i++){
    //     cout << mass[i] << ENDL;
    // }
    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}