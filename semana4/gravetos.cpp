#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n;
  cin >> n;

  ll m = n / 2;

  vector<ll> gr;
  ll x;
  while ( n-- ) {
    cin >> x;
    gr.push_back(x);
  }

  sort(gr.begin(), gr.end());
  m = gr[m];

  ll cnt = 0;
  for ( ll x : gr ) {
    cnt += abs(x - m);
  }

  cout << cnt << "\n";
}
