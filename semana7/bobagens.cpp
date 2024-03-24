#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void fat(ull n) {
  vector<pair<ull, ull>> primes;
  for (ull i = 2; i*i <= n; i++) {
    ull cnt = 0;
    while (n % i == 0) { 
      n /= i; cnt++;
    }

    if(cnt > 0) {
      primes.push_back(make_pair(i, cnt));
    }
  }

  if (n > 1) { primes.push_back(make_pair(n, 1)); }
  sort(primes.begin(), primes.end(), 
       [](pair<ull, ull> lhs, pair<ull, ull> rhs) {
          return rhs.first < lhs.first;
        });

  for ( auto pr : primes ) {
    cout << pr.first << " " << pr.second << "\n";
  }
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
