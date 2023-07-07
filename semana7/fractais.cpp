#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<bool> sieve (1e7+15, true);

void eratosthenes (ull n) {
  for (ll i = 2; i * i <= n; i++) if (sieve[i])
    for (ll j = i * i; j <= n; j += i)
      sieve[j] = false;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  eratosthenes(1e5 + 15);

  ull t;
  cin >> t;
  while (t--) {
    ull k, n; 
    cin >> n >> k;

    ull cnt = 0;
    ull j = 0;
    vector<ull> p(k, 0);

    for (ull i = 1e5 + 15; i >= 1; i--) {
      if (sieve[i]) { 
        p[j++] = i; cnt++;
        if (cnt == k) {
          ull mult = 1;
          ull mult_t = 1;
          bool err = false;
          for (ull m = 0; m < k; m++) {
            mult_t = mult * p[m];
            if (mult_t/mult != p[m]) {
              err = true;
              break;
            }
            mult = mult_t;
          }
          if (!err && mult <= n) {
            cout << mult << "\n";
            break;
          }
          cnt--;
          j = j % k;
        }
      }
    }
  }
}
