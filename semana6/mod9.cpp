#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bit(112345, 0);
ll N = 0;

void add(ll i, ll delta) {
  for (; i < N; i += i & (-i))
    bit[i] += delta;
}

ll get(ll i) {
  ll ans = 0;
  for (; i > 0; i -= i & (-i))
    ans += bit[i];

  return ans;
}

int main() {
 cin.tie(0);
 ios_base::sync_with_stdio(0);

  ll n;
  cin >> n;
  N = n + 1;  

  ll x;
  string s;
  cin >> s;
  //cout << s << "\n\n";
  for ( int i = 0; i < n; i++  ) {
    add(i+1, s[i] - 48);
    //cout << s[i] << ":" << s[i] - 48<< " ";
  }

  int q;
  ll a1, a2, b1, b2, op, a, b, r, d;
  ll i, v;
  cin >> q;
  while ( q-- ) {
    cin >> op;
    switch ( op ) {
      case 1:
        cin >> a1 >> a2 >> b1 >> b2 >> d;
        a = get(a2) - (a1 - 1 >= 1 ? get(a1-1) : 0);
        b = get(b2) - (b1 - 1 >= 1 ? get(b1-1) : 0);
        r = a + b; 
        //cout << get(a2) << " " << get(a1-1) << " " << get(a2) - get(a1-1) << "\n";
        //cout << get(b2) << " " << get(b1-1) << " " << get(b2) - get(b1-1) << "\n\n";
        //cout << "r:" << r << " a:" << a << " b:" << b << "\n";
        (r - ( (r/9) * 9))  == d ? cout << "YES\n" : cout << "NO\n";
        break;

      case 2:
        cin >> a1 >> a2 >> b1 >> b2 >> d;
        a = get(a2) - (a1 - 1 >= 1 ? get(a1-1) : 0);
        b = get(b2) - (b1 - 1 >= 1 ? get(b1-1) : 0);
        r = a * b;
        //cout << get(a2) << " " << get(a1-1) << " " << get(a2) - get(a1-1) << "\n";
        //cout << get(b2) << " " << get(b1-1) << " " << get(a2) - get(a1-1) << "\n\n";
        //cout << "r:" << r << " a:" << a << " b:" << b << "\n";
        (r - ( (r/9) * 9)) == d ? cout << "YES\n" : cout << "NO\n";
        break;

      case 3:
        cin >> i >> v;
        add(i, -(get(i) - (i-1 >= 1 ? get(i-1) : 0)) + v);
        break;
    }
  }
}
