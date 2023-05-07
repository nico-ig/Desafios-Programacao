#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

map<ull, ull> memo;

ull f(ull n) {
  if ( memo.contains(n) ) { return memo[n]; }

  ull res = f(n/3) + f(n/2);
  memo[n] = res;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ull n;
  cin >> n;

  memo[0] = 1;
  cout << f(n) << "\n";
}
