#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> g(1e3 + 15);
set<int> s;

void dfs(int u) {
  s.erase(u);
  for ( int v : g[u] ) {
    if ( s.find(v) != s.end() ) {
      s.erase(v);
      dfs(v);
    }
  } 
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, m;
  cin >> n >> m;
  ll u, v;
  while ( m-- ) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  for ( int i = 0; i < n; i++ ) { s.insert(i); }

  int cnt = 0;
  while ( s.size() > 0 ) {
     dfs(*s.begin());
     cnt++;
  }

  cout << cnt << "\n";
}
