#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using edge = pair<int, int>;
#define oo 1123456789012345678

ull N;
vector<vector<edge>> g (1e5);
vector<ull> d (1e5, oo);
vector<bool> vis (1e5);

void dijkstra(ull src) {
  priority_queue<pair<ull, ull>,
  vector<pair<ull, ull>>, greater<pair<ull, ull>>> Q;
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
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ull m; cin >> N >> m;
  while (m--) {
    ull u, v, w; cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  ull min_d = oo;
  for (ull i = 0; i < N; i++) {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), oo);

    dijkstra(i);

    ull max_v = 0;
    for (ull u = 0; u < N; u++) {
      if ( u == i ) { continue; }
      max_v = max(max_v, d[u]);
    }

    min_d = min(min_d, max_v);
  }

  cout << min_d << "\n";
}
