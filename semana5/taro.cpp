#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n, p;
  cin >> n;
  vector<vector<ll>> pontos(5, vector<ll>(n + 15, 0));

  for (ll d = 1; d <= n; d++) {
    for (ll a = 0; a < 3; a++) {
      cin >> p;
      pontos[a][d] = p;
    }
  }

  vector<vector<ll>> mem(5, vector<ll>(n + 15, 0)); 
  for (ll d = 1; d <= n; d++) {
    for (ll a = 0; a < 3; a++) {
      mem[a][d] = max(mem[(a+1)%3][d-1], mem[(a+2)%3][d-1]) + pontos[a][d];
    }
  }

  ll max_p = max(mem[0][n], mem[1][n]);
  max_p = max(max_p, mem[2][n]);
  cout << max_p << "\n";
}
