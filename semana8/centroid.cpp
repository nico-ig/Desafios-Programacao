#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g(2*1e5 + 15);
vector<int> visited(2*1e5 + 15);
int n;

ll dfs(ll u) {
  ll tam_arvore = 1, tam_sub_arvore;
  bool is_centroid = true;
  visited[u] = true;
  for ( int v : g[u] ) if (!visited[v]) {
    tam_sub_arvore = dfs(v);
    tam_arvore += tam_sub_arvore;
    if ( tam_sub_arvore > n/2 ) { is_centroid = false; break; }
  } 

  if ( is_centroid && (n - tam_arvore <= n/2) ) {
    cout << u << "\n";
    exit(0);
  } 
  return tam_arvore;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
 
  cin >> n;

  int u, v;
  int tmp = n - 1;
  while (tmp--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);
}
