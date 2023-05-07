#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll a, b, n;
  cin >> a >> b >> n;

  ll p;
  vector<ll> v;
  for(int i = 0; i < n; i++) { cin >> p; v.push_back(p); }

  // Pegando as interseccoes
  vector<ll> scj;
  vector<vector<ll>> inters(n+1);
  for ( ll s = 1; s < (1<<n); s++ ) {
    ll m = 1;
    ll cnt = 0;
    for ( ll i = 0; i < n; i++ ) 
      if (s & (1<<i)) { m*=v[i]; cnt++; }
    
    inters[cnt].push_back(m);
    scj.clear();
  }

  ll r = 0;
  a = a-1;
  for ( int i = 1; i < inters.size(); i++ ) {
    ll soma = 0;
    for ( ll k : inters[i] ) 
      soma += (b/k - a/k);

    int m = i % 2 == 0 ? -1 : 1;
    r += m*soma;
  }
    
  cout << b - a - r << "\n";
}
