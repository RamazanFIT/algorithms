#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    // int n;
    // cin >> n;
    // int m;
    // cin >> m;
    // vector<pair<int, int>> g;
    // for(int i = 0; i < m; i++){
    //     int a, b;
    //     cin >> a >> b;
    //     g.push_back(make_pair(a, b)); // edges 
    // }
    // KMP reali 
    // TOPSORT 
    // hash task 
    // sorting merge sort and quick sort 
    
    // pseudocode 

    // string a;
    // int l, r;
    // string s;
    // a[l r] == s ? 
    // O(1) 
    // precalc 
    // O(a.size()) 
    
    // query 
    // O(1) 
    // pseudocode 
    
    // BONUS TASK 

    // graph 
    // set -> vertex 
    // vertex -> рядом с set 
    // pseudocode 
    // O(m)
    // vector<int> ans;
    // return ans;
    // int n;cin>>n;
    // vector<vector<int>> g; // adj list 
    // vector<int> color(n + 1, 666); // blue
    // set<int> set_;

    // for(auto it : set_){
    //     color[it] = 777; //red
    // }
    // vector<int> ans;
    // for(int i = 1; i <= n; i++){ // 1 do n 
    //     for(int j = 0; j < g[i].size(); j++){
    //         if(color[j] != color[i]){ // neigh u i vertex
    //             ans.push_back(j);
    //         }
    //     }
    // }
    // 4  
    // sorting hash color dfs->topsort dfs 
    // print ans;
    // KMP
    // // 'ramazanrama' 
    // // prefixfunction 
    // 0 1 3 2 313  31 3 
    // 13 131 3131 313 131
    // 313 131 32 32 323 32
    // 1231 31 313 131 31 31
    // 313 1313 131 31 3 13
    string s;
    cin >> s;
    vector<int> p(s.size());
    int last = 0;
    int i = 1;
    while(i < s.size()){
        if(s[i] == s[last]){
            p[i] = ++last;
        } else if(last == 0){
            i++;
        } else{
            last = p[last - 1];
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << p[i] << " ";
    }
    // KMP 9
    // Rabin Karp 8
    // graph 10 
    // graph 11
    // graph 12 
    

    // heap 
    // buble 
    // merge 
    // quick 

    // from bonus 
    // O(sqrt * n);
    // O(n + m) 
    // O(m * m) 
    // O(n * n) 
    

}