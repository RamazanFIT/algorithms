#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;





signed main(){
    
    goodluck

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<set<int> > g(n + 1);
    vector<int> color(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        int v;
        cin >> v;
        if(type == 1){
            color[v] = 1;
        } else{
            queue<pair<int, int> > q;
            q.push(make_pair(v, 0));
            vector<bool> bolean(n + 1, 0);
            bolean[v] = true;
            bool check = true;
            if(color[v]){
                cout << 0 << ENDL;
                continue;
            }
            while(!q.empty()){


                for(auto it : g[q.front().ff]){
                    if(bolean[it]) continue;
                    if(color[it]){
                        cout << q.front().ss + 1 << ENDL;
                        check = false;
                        break;
                    } else{
                        q.push(make_pair(it, q.front().ss + 1));
                    }
                    bolean[it] = true;

                }
                q.pop();
                if(check == false){
                    break;
                }
              
            }
            if(check){
                cout << -1 << ENDL;
            }
        }
    }
    
    
    


    endd
}