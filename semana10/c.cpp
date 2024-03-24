#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define NEUTRAL 0
#define FACTOR(sz) sz
#define OP(X, Y) (X + Y)

const ll N = 2e5+15;
const ll L = ceil(log2(N));
struct dlta { ll add = 0, set = -1; };

vector<ll> t (2*N); vector<dlta> delta (2*N);

void build(vector<ll>& src) {
    for (ll i = 1; i < src.size(); i++)
        t[N+i] = src[i];
    for (ll ti = N-1; ti > 0; ti--)
        t[ti] = OP(t[2*ti], t[2*ti+1]);
}

ll apply(ll ti, dlta d, ll sz) {
    if (d.set != -1) {
        t[ti] = ll(d.set) * FACTOR(sz);
        delta[ti] = { 0, d.set };
    }
    if (d.add != 0) {
        t[ti] += ll(d.add) * FACTOR(sz);
        delta[ti].add += d.add;
    }
    return t[ti];
}

void pull(ll i) {
    for (ll s = __builtin_ctz(i)+1; s < L; s++) {
        ll ti = i >> s;
        t[ti] = OP(t[2*ti], t[2*ti+1]);
    }
}

void push(ll i) {
    ll sz = 1 << (L-1);
    for (ll s = L; s > 0; s--, sz /= 2) {
        ll ti = i >> s;
        apply(2*ti, delta[ti], sz);
        apply(2*ti+1, delta[ti], sz);
        delta[ti] = {};
    }
}

void apply_inclusive(ll l, ll r, char op = '\0', ll x = 0) {
    r++;
    dlta d;
    if (op == '+') { d.add = x; }
    if (op == '=') { d.set = x; }
    ll tl = l += N, tr = r += N, sz = 1;
    push(tl); push(tr);
    for (; l < r; l /= 2, r /= 2, sz *= 2) {
        if (l & 1) { apply(l++, d, sz); }
        if (r & 1) { apply(--r, d, sz); }
    }
    pull(tl); pull(tr);
}

void add_inclusive(ll l, ll r, ll d) {
    apply_inclusive(l, r, '+', d);
}

void set_inclusive(ll l, ll r, ll d) {
    apply_inclusive(l, r, '=', d);
}

ll op_inclusive(ll l, ll r) {
  r++;
  ll tl = l += N, tr = r += N, sz = 1;
  push(tl); push(tr);
  ll ans = NEUTRAL;
  for (; l < r; l /= 2, r /= 2, sz *= 2) {
    if (l & 1) { ans = OP(ans, apply(l++, dlta(), sz)); }
    if (r & 1) { ans = OP(ans, apply(--r, dlta(), sz)); }
  }
  pull(tl); pull(tr);
  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;

  vector<ll> src(n+1);
  for (ll i = 1; i <= n; i++) { 
    cin >> src[i]; 
  }
  build(src);

  while(q--) {
    ll op, i, j, k;
    cin >> op;
    if(op == 1) {
      cin >> i >> j >> k;
      add_inclusive(i, j, k);
    } else if (op == 2) {
      cin >> i >> j >> k;
      set_inclusive(i, j, k);
    } else if (op == 3) {
      cin >> i >> j;
      cout << op_inclusive(i, j) << "\n";
    }
  }
}
