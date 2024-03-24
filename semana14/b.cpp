#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pt = complex<ld>;

#define px real()
#define py imag()

ld dot(pt a, pt b) { 
  return (conj(a) * b).px; 
}

ld cross(pt a, pt b) { 
  return (conj(a) * b).py; 
}

ld polygon_area(vector<pt>& ps) {
  ld area = cross(ps[ps.size()-1], ps[0]);
  
  for (int i = 1; i < ps.size(); i++) {
    area += cross(ps[i-1], ps[i]);
  }

  return area / 2.0;
}

ull p_seg(ll x1, ll y1, ll x2, ll y2) {
  ull dx = abs(x1 - x2);
  ull dy = abs(y1 - y2);

  return gcd(dx, dy) + 1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n; 
  cin >> n;
  vector<pt> ps(n);

  ll x, y, x_ant, y_ant, x1, y1;

  cin >> x1 >> y1;
  x_ant = x1;
  y_ant = y1;
  ps[0] = pt(x1, y1);

  ull pb = 0;
  for(int i = 1; i < n; i++) {
    cin >> x >> y;
    ps[i] = pt(x, y);

    pb = pb + p_seg(x_ant, y_ant, x, y);
    x_ant = x;
    y_ant = y;
  }

  pb = pb + p_seg(x, y, x1, y1);
  pb = pb - n;

  ld A = abs(polygon_area(ps) - 0);

  ull pi = (ll)A + 1 - pb/2;

  cout << pi << " " << pb << "\n";
}
