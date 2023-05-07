#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bit(112345, 0);
ll N = 0;

void add(ll i, ll delta) {
  for (; i < N; i += i & (-i))
    bit[i] += delta;
}

ll get(ll i) {
  ll ans = 0;
  for (; i > 0; i -= i & (-i))
    ans += bit[i];

  return ans;
}

ll bb(ll x) {
  ll lo = 1, hi = N;
  ll get_v, mi;

  while ( lo < hi ) {
    mi = lo + (hi - lo)/2;
    get_v = get(mi);
    //cout << "get_v:" << get_v << "x:" << x <<"\n";
    //if ( get_v == x ) { break; }
    if ( get_v < x ) { lo = mi + 1; }
    else { hi = mi; }
  }

  return lo; 
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n, r;
  cin >> n >> r;
  N = n + 1;  

  ll x;
  vector<ll> fita(n+10);
  for ( int i = 1; i <= n; i++ ) {
    cin >> x;
    add(i, 1);
    fita[i] = x;
  }

  ll mc;
  char op;
  ll cabeca = 1;
  while ( r-- ) {
    cin >> op;

    switch ( op ) {
      case 'm':
        cin >> mc;
        cabeca += mc;
        break;

      case 'q':
        cout << fita[bb(cabeca)] << "\n"; 
        break;

      case 'd':
        add(bb(cabeca), -1);
        break;
    }
  }
}
