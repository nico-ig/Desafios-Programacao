#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, p, h, f, d, c, mi, l, max_t, min_t, max_i, min_i;
  cin >> n;
  while ( n-- ) {
    cin >> p >> h >> f >> d >> c;

    if ( d > c ) { max_t = d; min_t = c; max_i = h; min_i = f; }
    else         { max_t = c; min_t = d; max_i = f; min_i = h; }

    p = p / 2;
      
    mi = min(p, max_i);
    p -= mi;
    l = mi * max_t;
    l += min(p, min_i) * min_t;  
    cout << l << "\n";
  }
}
