#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n;
  cin >> n;
  while (n--) {
    ll x, y, ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    x = abs(ax - bx); 
    y = abs(ay - by);
    cout << gcd(x, y) + 1 << "\n";
  }
}
