#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

#define NEUTRAL 0
#define OP(X, Y) max(X, Y)

const int N = 2e5+15;
const int L = log2(N);

vector<vector<ii>> g (N);
vector<int> depth (N, 0);
vector<vector<int>> weiop (N, vector<int>(L+1));
vector<vector<int>> up (N, vector<int>(L+1));

void bl_euler_tour(int u, int p, int w) {
  up[u][0] = p; weiop[u][0] = w; depth[u] = depth[p] + 1;
  for (auto [v, w] : g[u]) if (v != p)
    bl_euler_tour(v, u, w);
}

void bl_init(int u, int n) {
  depth[u] = 0; bl_euler_tour(u, u, 0);
  for (int l = 0; l < L; l++)
    for (int u = 0; u < n; u++) {
      int a = up[u][l];
      up[u][l+1] = up[a][l];
      weiop[u][l+1] = OP(weiop[u][l], weiop[a][l]);
    }
}

int bl(int f, int k) {
  for (int l = L; l >= 0; l--) if (k & (1 << l))
    f = up[f][l];

  return f;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  for (ll f = 2; f <= n; f++) {
    ll c;
    cin >> c;
    g[c].push_back(ii(f, 0));
  }

  g[0].push_back(ii(0, 0));
  g[0].push_back(ii(1, 0));
  bl_init(0, n+1);

  while (q--) {
    int f, k; cin >> f >> k;
    int ret = bl(f, k);
    cout << (ret == 0 ? -1 : ret) << "\n";
  }
}
