#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, a;
  cin >> n;

  int n1 = n;
  vector<ll> v;
  while ( n1-- ) {
    cin >> a;
    v.push_back(a);
  }

  ll m = 1073741824;
  vector<ll> cj;
  for ( int s = 0; s < (1<<n-1); s++ ) {
    ll a = v[0];
    for ( int i = 0; i < n-1; i++ ) {
      if ( s & (1<<i) ) { cj.push_back(a); a = v[i+1]; }
      else { a |= v[i+1]; }
    }

    cj.push_back(a);

    a = cj[0];
    for ( int i = 1; i < cj.size(); i++ )
      a ^= cj[i];
    cj.clear();

    m = min(a, m);
  }

  cout << m << "\n";
}
