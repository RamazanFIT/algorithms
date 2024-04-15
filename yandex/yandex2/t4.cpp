#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
  int u, v, w;
};

struct Node {
  int id;
  int dist;
  int max_time;

  bool operator<(const Node& other) const {
    return dist > other.dist;
  }
};

vector<vector<int>> adj;
vector<int> max_time;

void dijkstra(int n, vector<Edge>& edges) {
  vector<int> dist(n, INT_MAX);
  priority_queue<Node> pq;

  for (int i = 0; i < n; i++) {
    dist[i] = max_time[i];
    pq.push({i, dist[i], max_time[i]});
  }

  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();

    int u = node.id;
    if (dist[u] < node.max_time) {
      continue;
    }

    for (int v : adj[u]) {
      int d = dist[u] + edges[v].w;
      if (d <= max_time[v]) {
        dist[v] = d;
        pq.push({v, d, max_time[v]});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  max_time.resize(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int k;
  cin >> k;

  vector<Edge> proposals(k);
  for (int i = 0; i < k; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    u--; v--;
    proposals[i] = {u, v, w};
  }

  int p;
  cin >> p;

  for (int i = 0; i < p; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    a--; b--;
    max_time[a] = t;
    max_time[b] = t;
  }

  dijkstra(n, proposals);

  bool all_accessible = true;
  for (int i : max_time) {
    if (i == INT_MAX) {
      all_accessible = false;
      break;
    }
  }

  if (all_accessible) {
    cout << 0 << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
