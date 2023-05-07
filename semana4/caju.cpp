#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n, c, cnt = 0;
  cin >> n;

  while ( n-- ) {
    cin >> c;
    cnt += (c >= 10 ? c - 10 : 0);
  }

  cout << cnt << "\n";
}
