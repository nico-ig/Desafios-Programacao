#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int M = 1e9 + 7;

ull fast_pow(ll a, ll b) {
  if (b == 0) { return 1; } if (b == 1) { return a; }
  ll res = fast_pow(a, b/2);
  res = (res * res) % M;
  if (b % 2) res = (res * a) % M;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull t;
  cin >> t;

  while(t--) {
    ull n;
    cin >> n;

    ull cnt = n / 9;
    ull pot = fast_pow(10, cnt);

    //ull d = ((n % 9) * pot + (pot - 1)) % M;

    ull dig = (((n % 9) % M) * (pot % M)) % M;
    ull nines = (pot - 1) % M;
    ull d = (dig + nines) % M;

    cout << d << "\n";
  }
}
