#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, char>> a(1e5 + 15);
ll swaps = 0;

void ms(ll l, ll r) {
  if ( r - l == 1 ) { return; }
  int mi = l + (r - l)/2;
  ms(l, mi); ms(mi, r);

  vector<pair<ll, char>> aux(r - l);
  ll i = l, j = mi;  
  for ( ll k = 0; k < r - l; k++ ) {
    if ( i < mi && j < r ) {
      if ( !(a[i].first < a[j].first) && a[j].second == 'A') { swaps += mi - i;  } 
      if ( a[i] < a[j] ) { aux[k] = a[i++]; } 
      else { aux[k] = a[j++]; }
    } else if ( i < mi ) { aux[k] = a[i++]; }
    else { aux[k] = a[j++]; }
  }

  copy(aux.begin(), aux.end(), a.begin() + l);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n, x, h;
  cin >> n >> h;

  for ( ll i = 0; i < h; i++ ) {
    cin >> x;
    a[i] = make_pair(x, 'H');
  }

  for ( ll i = h; i < n; i++ ) {
    cin >> x;
    a[i] = make_pair(x, 'A');
  }

  ms(0, n);
  cout << swaps << "\n";
}
