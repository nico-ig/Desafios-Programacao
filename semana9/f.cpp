#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int, int>;

const int N = 1e5+15; const int oo = 1123456789;

vector<vector<edge>> g (N);
vector<int> d (N, oo);
vector<bool> vis (N);

void dijkstra(int src) {
  priority_queue<pair<ll, int>,
  vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  d[src] = 0;
  Q.push({0, src});
  while (!Q.empty()) {
    auto [c, u] = Q.top(); Q.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    for (auto [v, w] : g[u])
    if (d[v] > d[u] + w) {
      d[v] = d[u] + w;
      Q.push({d[v], v});
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v, w; 
    cin >> u >> v >> w; 
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  dijkstra(0);
  int ds[N];
  memcpy(ds, &d[0], N*sizeof(int));

  fill(d.begin(), d.end(), oo);
  fill(vis.begin(), vis.end(), false);

  dijkstra(n-1);
  int de[N];
  memcpy(de, &d[0], N*sizeof(int));

  int cnt = 0;
  for (int u = 0; u < n; u++) {
    for (auto [v, w] : g[u]) {
      if (ds[u] + w + de[v] == ds[n-1]) {
        cnt = cnt + w;
      }
    }
  }

  cout << cnt * 2 << "\n";
}
