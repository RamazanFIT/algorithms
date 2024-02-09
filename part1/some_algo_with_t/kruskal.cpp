#include <bits/stdc++.h>

using namespace std;
vector<int> color;


int dsu_get(int v){
    if(color[v] == v){ // color[v] == v the v - is king
        return v; // v - king
    } else{
        color[v] = dsu_get(color[v]); // give us the king of V
        return color[v]; // update the king
    } // give us the king of V
    // father 
}

void dsu_merge(int x, int y){
    x = dsu_get(x); // x - king
    y = dsu_get(y); // y - king
    // 1234 & 1 = 0 
    // 1233 & 1 = 1
    if(rand() & 1){
        swap(x, y); // x or y x = y  y = x
    }
    color[x] = y; // change the king
}


int main(){
    

    /////////
    int n;
    cin >> n;
    int m;
    cin >> m; 
            // cost        a   b
    vector<pair<int, pair<int, int>>> g; // vector edges 
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g.push_back(make_pair(cost, make_pair(a, b)));
    }  // get info about graph 
    ///////////

    // sort the graph with the cost 
    sort(g.begin(), g.end());
    color = vector<int>(n + 1); // creating the color array
   
    for(int i = 1; i <= n; i++){
        color[i] = i;  // initially the vertex v have v - color 
    } 
    int costMST = 0; // sum of the edges in MST
    for(int i = 0; i < m; i++){
        // MAIN PART OF ALGO 
        int a = g[i].second.first;  // vertex a
        int b = g[i].second.second; // vertex b
        int w = g[i].first; // weight between a and b
        if(dsu_get(a) != dsu_get(b)){ // war
            costMST += w;
            dsu_merge(a, b); // fight 
        }
    }
    cout << costMST;


}