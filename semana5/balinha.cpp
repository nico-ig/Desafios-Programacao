#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> mem(7, vector<ll>(3*1e4 + 15, -1));
vector<ll> v{0, 1, 5, 10, 25, 50};

ll pd(ll i, ll c) {
  if ( c < 0 ) {
    return 0;
  }

  if ( c == 0 ) {
    return 1;
  }

  if (mem[i][c] != -1 )
    return mem[i][c];

  ll sum = 0;
  for ( ll k = i; k <= 5; k++ ) {
      sum += pd(k, c - v[k]);
  }

  mem[i][c] = sum;
  return sum;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n;
  while( cin >> n ) {
    cout << pd(1, n) << "\n";
  }
}
