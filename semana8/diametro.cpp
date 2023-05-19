#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> g(2e5 + 15);
vector<bool> visited(2e5 + 15, false);

ll dfs(ll u, ll* last) {
  ll h = 0, vm, v_last = u, max = 0;
  visited[u] = true;
  for ( int v : g[u] ) if (!visited[v]) {
    visited[u] = true;
    h = dfs(v, &vm);
    if ( h > max ) {
      max = h;
      v_last = vm;
    }
  }
  *last = v_last;
  return max + 1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n; cin >> n;
  ll u, v;
  n--;
  while ( n-- ) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ll h, last;
  h = dfs(1, &last);
  fill(visited.begin(), visited.end(), false);
  cout << dfs(last, &last) - 1 << "\n";
}
