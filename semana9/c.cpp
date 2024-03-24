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

void dijkstra(ull src, ull r) {
  priority_queue<pair<ull, ull>,
  vector<pair<ull, ull>>, greater<pair<ull, ull>>> Q;
  d[src] = 0;
  Q.push({0, src});
  while (!Q.empty()) {
    auto [c, u] = Q.top(); Q.pop();
    if (vis[u]) { continue; }
    vis[u] = true;

    if (u < r) {
      for (auto [v, w] : g[u]) {
        if (v == u+1 && d[v] > d[u] + w) {
          d[v] = d[u] + w;
          Q.push({d[v], v});
        }
      }
    }

    else { 
      for (auto [v, w] : g[u]) {
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w;
          Q.push({d[v], v});
        }
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull m, c, k;
  cin >> N >> m >> c >> k;

  for (int i = 0; i < m; i++) {
    ull u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  dijkstra(k, c-1);
  cout << d[c-1] << "\n";
}
