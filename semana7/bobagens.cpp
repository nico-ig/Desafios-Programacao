#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void fat(ull n) {
  for (ull i = sqrt; i*i <= n; i++) {
    ull cnt = 0;
    while (n % i == 0) { 
      n /= i; cnt++;
    }

    if(cnt > 0) {
      cout << i << " " << cnt << "\n";
    }
  }

  if (n > 1) { cout << n << " " << 1 << "\n"; }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull t;
  cin >> t;

  while (t--) {
    ull k, n = 1;
    cin >> k;
    while (k--) {
      ull p, e;
      cin >> p >> e;
      n *= pow(p, e);
    }
    fat(n-1);
  }
}
