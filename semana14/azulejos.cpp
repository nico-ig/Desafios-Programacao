#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) {
    unsigned long long n;
    cin >> n;
    if ( n % 2 == 1 ) {
      cout << "NO\n";
      continue;
    }

    if (__builtin_popcount(n) == 1 || ((n/2) % 9) == 0) {
      cout << "YES" << "\n";
      continue;
    }

    cout << "NO\n";
  }
}
