#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<ull> fat(1e4+15);

ull m = 1e9 + 7;
ull N;
vector<ull>B(1e4+15, 0);
vector<ull>K(1e4+15, 0);

ull fast_pow(ull a, ull b) {
  if (b == 0) {
    return 1;
  }

  if (b == 1) {
    return a;
  }

  ull res = fast_pow(a, b/2);
  res = (res * res) % m;
  
  if (b % 2) {
    res = (res * a) % m;
  }
  
  return res;
}

void c_fat() {
  fat[0] = 1;

  ull f = 1;
  for(ull i = 1; i <= 1e4; i++) {
    f = ((f % m) * (i % m)) % m;
    fat[i] = f;
  }
}

ull bin(ull i) {
  ull a = fat[B[i]];
  ull b = fat[B[i] - (N-K[i])];

  b = fast_pow(b, m - 2) % m;

  return ((a % m) * (b % m)) % m;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull c;
  cin >> N >> c;

  for (int i = 1; i <= N; i++) {
    ull b;
    cin >> b;
    B[i] = b;
  }

  for (int i = 1; i <= c; i++) {
    ull m, n;
    cin >> m >> n;
    K[n] = K[n] + 1;
  }

  c_fat();
  ull res = 1;
  for (int i = 1; i <= N; i++) {
    res = ((res % m) * (bin(i) % m)) % m;
  }

  cout << res << "\n";
}
