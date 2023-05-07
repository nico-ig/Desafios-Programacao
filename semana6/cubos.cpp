#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n;
  cin >> n;

  vector<ll> v(0);
  ll h;
  while ( n-- ) {
    cin >> h;
    auto it = upper_bound(v.begin(), v.end(), h);
    if ( it == v.end() ) { v.push_back(h); }
    else { *it = h; }
  }

  cout << v.size() << "\n";
}
