#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull f = 1;
  ull m = 1e9 + 7;
  cout << "{1, ";
  for (int i = 1; i < 100; i++) {
    f = ((f % m) * i % m) % m;
    cout << f << ", ";
  }
  f = ((f % m) * (int)1e4 % m) % m;
  cout << f;
  cout << "};\n";
}
