#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int, int>;

#define oo 1000

ll N;
vector<int> d(N + 15, oo), vis(N + 15);
vector<vector<edge>> g(N + 15);

int prim(int src) {
  ll sum = 0;
  priority_queue<pair<int, int>,
  vector<pair<int, int>>, greater<pair<int, int>>> Q;
  Q.push(make_pair(d[src] = 0, src));
  while (!Q.empty()) {
    auto [c, u] = Q.top(); Q.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    sum += c;
    cout << "sum:" << sum << "c:" << c << "\n";
    for (auto [v, w] : g[u])
    if (!vis[v] && w < d[v])
      Q.push(make_pair(d[v] = w, v));
  }
  return sum;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll m;
  cin >> N >> m;
  
  ll u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  cout << prim(0) << "\n";
}
