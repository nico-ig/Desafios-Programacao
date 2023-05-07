#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n, m, h;
  cin >> n >> m;

  multiset<ll> s;
  while ( n-- ) {
    cin >> h;
    s.insert(h);
  }
  
  ll t;
  while ( m-- ) {
    cin >> t;
    if ( s.size() == 0 ) { cout << "-1\n"; continue; }

    auto it = s.upper_bound(t);
    if  ( it == s.begin() ) { cout << "-1\n"; }
    else { cout << *(--it) << "\n"; s.erase(it); }
  }
}
