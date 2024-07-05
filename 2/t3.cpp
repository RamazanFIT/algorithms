// /* 
//     Bismillah 
//  لا إله إلا الله محمد رسول الله
//  Al'-Phatixa
//  بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//  ٱلْحَمْدُ لِلَّهِ رَبِّ ٱلْعَٰلَمِينَ
//  ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//  مَٰلِكِ يَوْمِ ٱلدِّينِ
//  إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ
//  ٱهْدِنَا ٱلصِّرَٰطَ ٱلْمُسْتَقِيمَ
//  صِرَٰطَ ٱلَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ ٱلْمَغْضُوبِ عَلَيْهِمْ وَلَا ٱلضَّآلِّينَ
// */
// #include <bits/stdc++.h>
// #define ENDL "\n"
// #define ff first 
// #define ss second  
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define endd return 0;
// #define repeat(x) for(int _ = 0; _ < x; _++)
// #define vii vector<int>
// #define mii map<int, int>
// #define vvi vector<vector<int>>
// #define FORW(leftb,rightb,way) for(int i = leftb; i < rightb; i+=way)
// #define FOR(leftb,rightb) for(int i = leftb; i < rightb; i+=1)
// #define print(massive) \
//     for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
// #define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
// template<typename T>
// void get(T &a) {std::cin >> a;}
// template<typename T, typename... Args>
// void get(T &a, Args&... args) {std::cin >> a;get(args...);}
// template<typename T>
// void put(const T &a) {std::cout << a;}
// template<typename T, typename... Args>
// void put(const T &a, const Args&... args) {std::cout << a;put(args...);}

// using ll = long long;
// using namespace std;

// void solve(int ccase){
//     string a, b; get(a, b);

//     int l = 0;
//     int r = 0;
//     int answer = a.size() + b.size();
//     int cnt = 0;

//     while(r <= b.size()){
//         // cout << r << " " << l << ENDL;
//                     if(answer > a.size() + b.size() - cnt){
//                 answer = a.size() + b.size() - cnt;
//             }
//         if(a[l] == b[r]){
//             // cout << a[l] << " " << b[r] << ENDL;
//             cnt++;
//             l++;
//             r++;
//             // cout << cnt << ENDL;
//         } else{
//             // answer = min(answer,(a.size() + b.size() - cnt));
//             if(answer > a.size() + b.size() - cnt){
//                 answer = a.size() + b.size() - cnt;
//             }
//             l++;
//             // cnt = 0;
//         }
//         // cout << cnt << ENDL;
//         // cout << l << ": " << cnt << ENDL;
//         if(l >= a.size()){
//             if(answer > a.size() + b.size() - cnt){
//                 answer = a.size() + b.size() - cnt;
//             }
//             l = 0;
//             // cnt++;
//             r++;
//             cnt = 0;
//         }
//     }
//     cout << answer << ENDL;
    
// }

// signed main(){
    
//     goodluck
//     // freopen("std.in", "r", stdin);
//     // freopen("std.out", "w", stdout);

//     int t = 1;
//     cin >> t;
//     repeat(t) solve(_);
    

//     endd
// }