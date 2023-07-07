#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll N, M, K;
vector<ull> S(20, 0);
vector<vector<ull>> G(20, vector<ull>(20, 0));
vector<vector<ull>> mem(vector<vector<ull>> (6*1e5, vector<ull>(20, -1)));

ull dp(ull v, ll u) {
  if (__builtin_popcount(v) == M) 
    return 0;

  if (mem[v][u] != -1)
    return mem[v][u];

  ull max_s = 0;
  for (int p = 1; p <= N; p++) {
    if ( (v & (1 << p)) == 0 ) {
      ull v_aux = v | (1 << p);
      max_s = max(max_s, dp(v_aux, p) + G[u][p] + S[p]);
    }
  }

  mem[v][u] = max_s;
  return max_s;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  cin >> N >> M >> K;

  for(int i = 1; i <= N; i++) {
    ll s;
    cin >> s;
    S[i] = s;
  }

  for (int i = 1; i <= K; i++) {
    ll x, y, s;
    cin >> x >> y >> s;
    G[x][y] = s;
  }

  cout << dp(0, 0) << "\n";
}
