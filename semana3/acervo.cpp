#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> chosen (13);
vector<ll> p(12);

void gen(vector<vector<ll>> r, ll n, ll k) {
  if ( k == n ) {
    for ( ll i = 0; i < n; i++ )
      cout << p[i] << " ";
    cout << "\n";
    return;
  }

  bool pode = true;
  for ( ll i = 1; i <= n; i++ ) {
    if ( chosen[i] ) { continue; }

    // Pega cada restricao para i
    for ( ll restricao : r[i] )
      if ( restricao != -1 && chosen[restricao] == 1 ) { pode = false; break; }

    if ( !pode ) { continue; }

    chosen[i] = 1;
    p[k] = i;
    gen(r, n, k+1);
    chosen[i] = 0;
  }
} 

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n, c;
  cin >> n >> c;

  ll a, b;
  vector<vector<ll>> r(n+1, vector<ll>(1, -1));
  for ( int i = 0; i < c; i++ ) { cin >> a >> b; r[a].push_back(b); }
  gen(r, n, 0);
}
