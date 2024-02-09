#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int a, b, cost;
    Edge(int a, int b, int cost){
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cost;
            cin >> cost;
            edges.push_back(Edge(i, j, cost));
        }
    }
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
