#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a = 0;
ll n = 0;
ll cnt = 0;
vector<ll> v(1e5+15);

double calc_a(double h) {
  double s = 0;

  for ( int i = 0; i < n; i++ ) {
    if ( v[i] <= h ) { continue; }
    s += ( v[i] - h );
  }

  return s;
}

double bb(double lo, double hi) {
  double mi = lo + (hi - lo)/2;
  if ( cnt == 400 ) { return mi; }

  cnt++;
  double ac = calc_a(mi);
  if ( abs(ac - a) <= 0.00009 ) { return mi; } 
  if ( ac < a ) { return bb(lo, mi); }
  return bb(mi, hi);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll h;
  cin >> n >> a;
  while ( n != 0 && a != 0 ) {
    for ( ll i = 0; i < n; i++ ) {
      cin >> h;
      v[i] = h;
    }

    ll at = accumulate(v.begin(), v.begin() + n, 0);
    if ( abs(at - a) <= 0.00009 ) { cout << ":D\n"; }
    else if ( a > at ) { cout << "-.-\n"; }
    else { cout << fixed << setprecision(4) << 
      bb(0, 1e9) << "\n"; 
    }
    
    cnt = 0;
    cin >> n >> a;
  }
}
