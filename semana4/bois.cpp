#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, t, l;
  cin >> n;

  vector<int> v(10005, 0);
  while ( n-- ) {
    cin >> l >> t;
    while ( t > 0 && l > 0 ) {
      if ( v[t] < l ) { 
        int tmp = v[t];
        v[t] = l;
        l = tmp;
      }
      else { t--; }
    }
  }

  cout << accumulate(v.begin(), v.end(), 0) << "\n";
}
